//
// ---------- header ----------------------------------------------------------
//
// project       pig
//
// license       infinit (c)
//
// file          /home/mycure/infinit/pig/PIG.hh
//
// created       julien quintard   [fri jul 31 22:11:24 2009]
// updated       julien quintard   [thu mar  4 12:56:40 2010]
//

#ifndef PIG_PIG_HH
#define PIG_PIG_HH

//
// ---------- macros ----------------------------------------------------------
//

#define FUSE_USE_VERSION		26

//
// ---------- includes --------------------------------------------------------
//

#include <elle/Elle.hh>
#include <etoile/Etoile.hh>

#include <fuse.h>

namespace pig
{

//
// ---------- classes ---------------------------------------------------------
//

  ///
  /// XXX
  ///
  class PIG
  {
  public:
    //
    // static methods
    //
    static int	Getattr(const char*,
			struct stat*);
    static int	Setxattr(const char*,
			 const char*,
			 const char*,
			 size_t,
			 int);
    static int	Chmod(const char*,
		      mode_t);
    static int	Chown(const char*,
		      uid_t,
		      gid_t);

    static int	Access(const char*,
		       int);
    static int	Utimens(const char*,
			const struct timespec[2]);

    static int	Mknod(const char*,
		      mode_t,
		      dev_t);
    static int	Open(const char*,
		     struct fuse_file_info*);
    static int	Read(const char*,
		     char*,
		     size_t,
		     off_t,
		     struct fuse_file_info*);
    static int	Write(const char*,
		      const char*,
		      size_t,
		      off_t,
		      struct fuse_file_info*);
    static int	Truncate(const char*,
			 off_t);
    static int	Release(const char*,
			struct fuse_file_info*);
    static int	Unlink(const char*);
    static int	Rename(const char*,
		       const char*);

    static int	Symlink(const char*,
			const char*);
    static int	Readlink(const char*,
			 char*,
			 size_t);

    static int	Mkdir(const char*,
		      mode_t);
    static int	Readdir(const char*,
			void*,
			fuse_fill_dir_t,
			off_t,
			struct fuse_file_info*);
    static int	Rmdir(const char*);


    //
    // static methods
    //
    static Status	Initialize();
    static Status	Clean();

    //
    // static attributes
    //
    Door		etoile;
  };

}

#endif
