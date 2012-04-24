//
// ---------- header ----------------------------------------------------------
//
// project       elle
//
// license       infinit
//
// author        julien quintard   [mon jan 26 14:09:50 2009]
//

#ifndef ELLE_CRYPTOGRAPHY_PRIVATEKEY_HXX
#define ELLE_CRYPTOGRAPHY_PRIVATEKEY_HXX

//
// ---------- includes --------------------------------------------------------
//

#include <elle/cryptography/Digest.hh>

#include <elle/standalone/Maid.hh>
#include <elle/standalone/Report.hh>

#include <elle/idiom/Open.hh>

namespace elle
{
  using namespace standalone;

  namespace cryptography
  {

    template<typename T> Status
      PrivateKey::Decrypt(T const& in, Clear& out) const
      {
        elle::utility::Buffer buf;
        try
          {
            buf.Writer() << in;
          }
        catch (std::exception const& err)
          {
            escape("Cannot decrypt the object: %s", err.what());
          }

        return this->Decrypt(buf, out);
      }

    template<typename T>  Status
      PrivateKey::Encrypt(T const& in, Code& out) const
      {
        elle::utility::Buffer buf;

        try
          {
            buf.Writer() << in;
          }
        catch (std::exception const& err)
          {
            escape("Cannot save object: %s", err.what());
          }

        return this->Encrypt(buf, out);
      }

    template<typename T>  Status
      PrivateKey::Sign(T const& in, Signature& out) const
      {
        elle::utility::Buffer buf;

        try
          {
            buf.Writer() << in;
          }
        catch (std::exception const& err)
          {
            escape("Cannot save object: %s", err.what());
          }

        return this->Sign(buf, out);
      }
    ///
    /// these methods make it easier to decrypt/sign multiple items at
    /// the same time while keeping a way to catch errors.
    ///
    /// note that the Sign() methods cannot benefit from variadic templates
    /// since the last argument is not the variadic argument.
    ///

    //
    // decrypt
    //

    ///
    /// this method decrypts a code and returns pretty newly author
    /// objects.
    ///
    //template <typename T,
    //          typename... TT>
    //Status              PrivateKey::Decrypt(const Code&         code,
    //                                        T&                  parameter,
    //                                        TT&...              parameters)
    //  const
    //{
    //  Archive           archive;

    //  // extract an archive.
    //  if (this->Decrypt(code, archive) == Status::Error)
    //    escape("unable to decrypt into an archive");

    //  // extract the item.
    //  if (archive.Extract(parameter, parameters...) == Status::Error)
    //    escape("unable to extract the items");

    //  return Status::Ok;
    //}

    ////
    //// sign
    ////

    /////
    ///// this method signs an object by serializing it before applying the
    ///// signature process.
    /////
    //template <typename T1>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  // create th archive.
    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  // serialize the object.
    //  if (archive.Serialize(o1) == Status::Error)
    //    escape("unable to serialize the object");

    //  // re-launch the Sign() method for a digest.
    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     const T3&              o3,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     const T3&              o3,
    //                                     const T4&              o4,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     const T3&              o3,
    //                                     const T4&              o4,
    //                                     const T5&              o5,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     const T3&              o3,
    //                                     const T4&              o4,
    //                                     const T5&              o5,
    //                                     const T6&              o6,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6,
    //          typename T7>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     const T3&              o3,
    //                                     const T4&              o4,
    //                                     const T5&              o5,
    //                                     const T6&              o6,
    //                                     const T7&              o7,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6, o7) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6,
    //          typename T7,
    //          typename T8>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     const T3&              o3,
    //                                     const T4&              o4,
    //                                     const T5&              o5,
    //                                     const T6&              o6,
    //                                     const T7&              o7,
    //                                     const T8&              o8,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6, o7, o8) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6,
    //          typename T7,
    //          typename T8,
    //          typename T9>
    //Status              PrivateKey::Sign(const T1&              o1,
    //                                     const T2&              o2,
    //                                     const T3&              o3,
    //                                     const T4&              o4,
    //                                     const T5&              o5,
    //                                     const T6&              o6,
    //                                     const T7&              o7,
    //                                     const T8&              o8,
    //                                     const T9&              o9,
    //                                     Signature&             signature)
    //  const
    //{
    //  Archive           archive;
    //  Digest            digest;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6, o7, o8, o9) == Status::Error)
    //    escape("unable to serialize the objects");

    //  if (this->Sign(archive, signature) == Status::Error)
    //    escape("unable to sign the objects' archive");

    //  return Status::Ok;
    //}

    ////
    //// encrypt
    ////

    /////
    ///// this method takes any object and encrypts it.
    /////
    ///// the process obviously consists in serializing the object first.
    /////
    ///// note that Encrypt() methods return an archive hidden in the
    ///// code.
    /////
    //template <typename T1>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  // create an archive.
    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  // serialize the object.
    //  if (archive.Serialize(o1) == Status::Error)
    //    escape("unable to serialize the object");

    //  // encrypt the archive.
    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        const T3&           o3,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        const T3&           o3,
    //                                        const T4&           o4,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        const T3&           o3,
    //                                        const T4&           o4,
    //                                        const T5&           o5,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        const T3&           o3,
    //                                        const T4&           o4,
    //                                        const T5&           o5,
    //                                        const T6&           o6,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6,
    //          typename T7>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        const T3&           o3,
    //                                        const T4&           o4,
    //                                        const T5&           o5,
    //                                        const T6&           o6,
    //                                        const T7&           o7,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6, o7) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6,
    //          typename T7,
    //          typename T8>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        const T3&           o3,
    //                                        const T4&           o4,
    //                                        const T5&           o5,
    //                                        const T6&           o6,
    //                                        const T7&           o7,
    //                                        const T8&           o8,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6, o7, o8) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

    //template <typename T1,
    //          typename T2,
    //          typename T3,
    //          typename T4,
    //          typename T5,
    //          typename T6,
    //          typename T7,
    //          typename T8,
    //          typename T9>
    //Status              PrivateKey::Encrypt(const T1&           o1,
    //                                        const T2&           o2,
    //                                        const T3&           o3,
    //                                        const T4&           o4,
    //                                        const T5&           o5,
    //                                        const T6&           o6,
    //                                        const T7&           o7,
    //                                        const T8&           o8,
    //                                        const T9&           o9,
    //                                        Code&               code) const
    //{
    //  Archive           archive;

    //  if (archive.Create() == Status::Error)
    //    escape("unable to create the archive");

    //  if (archive.Serialize(o1, o2, o3, o4, o5, o6, o7, o8, o9) == Status::Error)
    //    escape("unable to serialize the object");

    //  if (this->Encrypt(archive, code) == Status::Error)
    //    escape("unable to encrypt the object's archive");

    //  return Status::Ok;
    //}

  }
}

#endif
