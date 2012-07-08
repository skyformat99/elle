#ifndef  ELLE_SERIALIZE_FOOTPRINT_HXX
# define ELLE_SERIALIZE_FOOTPRINT_HXX

# include <cassert>

# include <elle/IOStream.hh>

# include <elle/serialize/BinaryArchive.hh>

namespace elle
{
  namespace serialize
  {

    namespace detail
    {
      struct CounterStreamBuffer:
        public elle::StreamBuffer
      {
        size_t counter;
        char _buf[512];

        CounterStreamBuffer() : counter(0) {}

        virtual elle::Buffer write_buffer()
        {
          return elle::Buffer{
              _buf,
              sizeof(_buf) / sizeof(_buf[0])
          };
        }

        virtual elle::Buffer read_buffer()
        {
          assert("Should not be called");
          throw false;
        }

        virtual void flush(unsigned int size)
        {
          counter += size;
        }
      };
    }

    template <typename Archive = OutputBinaryArchive, typename T>
    size_t footprint(T const& value)
    {
      // XXX[ugly: we sould not be forced to allocate an instace so
      //     as to pass it to the IOStream!!!]
      detail::CounterStreamBuffer* streambuf =
        new detail::CounterStreamBuffer;
      elle::IOStream out(streambuf);
      Archive(out, value);
      return streambuf->counter;
    }

  }
}

#endif
