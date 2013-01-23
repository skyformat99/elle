#include <nucleus/proton/Base.hh>
#include <nucleus/proton/MutableBlock.hh>
#include <nucleus/Exception.hh>

#include <elle/idiom/Open.hh>

namespace nucleus
{
  namespace proton
  {
    /*----------.
    | Constants |
    `----------*/

    cryptography::oneway::Algorithm const Base::Constants::oneway_algorithm(
      cryptography::oneway::Algorithm::sha256);

    /*-------------.
    | Construction |
    `-------------*/

    Base::Base()
    {
    }

    Base::Base(MutableBlock const& block):
      _revision(block.revision()),
      _digest(cryptography::oneway::hash(block,
                                         Base::Constants::oneway_algorithm))
    {
    }

    /*--------.
    | Methods |
    `--------*/

    elle::Boolean
    Base::matches(MutableBlock const& block) const
    {
      Base base(block);

      // Compare the bases.
      return (*this == base);
    }

    /*----------.
    | Operators |
    `----------*/

    elle::Boolean
    Base::operator ==(Base const& other) const
    {
      if (this == &other)
        return true;

      // compare the attributes.
      if ((this->_revision != other._revision) ||
          (this->_digest != other._digest))
        return false;

      return true;
    }

    /*---------.
    | Dumpable |
    `---------*/

    elle::Status
    Base::Dump(elle::Natural32              margin) const
    {
      elle::String      alignment(margin, ' ');

      std::cout << alignment << "[Base]" << std::endl;

      // dump the revision.
      if (this->_revision.Dump(margin + 2) == elle::Status::Error)
        escape("unable to dump the revision");

      // dump the digest.
      std::cout << alignment << elle::io::Dumpable::Shift
                << "[Digest] " << this->_digest << std::endl;

      return elle::Status::Ok;
    }

    /*----------.
    | Printable |
    `----------*/

    void
    Base::print(std::ostream& stream) const
    {
      stream << "base{"
             << this->_revision
             << "}";
    }
  }
}
