
#include "libft.h"
#include <sys/stat.h> 	// file info
#include <time.h> 		// time formating
#include <dirent.h> 	// dir access
#include <sys/types.h> 	// type constant
#include <pwd.h> 		// user info
#include <grp.h>		// Group info

char	*build_perm_string(mode_t m)
{
	char	*dt;
	
	dt = ft_strnew(10);
	dt[0] = (S_ISDIR(m) ? 'd' : '-');
	dt[1] = (m & S_IRUSR ? 'r' : '-');
	dt[2] = (m & S_IWUSR ? 'w' : '-');
	dt[3] = (m & S_IXUSR ? 'x' : '-');
	dt[4] = (m & S_IRGRP ? 'r' : '-');
	dt[5] = (m & S_IWGRP ? 'w' : '-');
	dt[6] = (m & S_IXGRP ? 'x' : '-');
	dt[7] = (m & S_IROTH ? 'r' : '-');
	dt[8] = (m & S_IWOTH ? 'w' : '-');
	dt[9] = (m & S_IXOTH ? 'x' : '-');
	return (dt);
}

int		main(int argc, char **argv)
{
	struct stat 	sb; 
	struct passwd 	*pwd;
	struct group 	*grp;
	char 			*perm;

	if (argc < 2)
	{
		ft_printf("No file specified.\n");
		return (0);
	}
	
	if (stat(argv[1], &sb) < 0)
	{
		ft_printf("Invalid file\n");
		return (0);
	}

	// nom
	ft_printf("Nom (+ maybe uri): %s\n", argv[1]);
	
	// Type
	ft_printf("Type: ");
	if (S_ISDIR (sb.st_mode))
		ft_printf("Dossier\n");
	else if (S_ISREG (sb.st_mode))
		ft_printf("Fichier\n");
	else if (S_ISCHR (sb.st_mode))
		ft_printf("Character device\n");
	else if (S_ISBLK (sb.st_mode))
		ft_printf("Block device\n");
	else if (S_ISFIFO (sb.st_mode))
		ft_printf("FIFO\n");
	else if (S_ISLNK (sb.st_mode))
		ft_printf("Link\n");
	else if (S_ISSOCK (sb.st_mode))
		ft_printf("Socket\n");
	else
		ft_printf("Inconue\n");

	// Modes
	perm = build_perm_string(sb.st_mode);
	ft_printf("Mode: %s\n", perm);
	free(perm);
	
	// Nombre de liens
	ft_printf("Nombre de lien: %i\n", sb.st_nlink);
	
	// Proprietaire
	pwd = getpwuid(sb.st_uid);
	ft_printf("Proprietaire: %s\n", pwd->pw_name);
	
	// Groupe
	grp = getgrgid(pwd->pw_gid);
	ft_printf("Groupe: %s\n", grp->gr_name);
	
	// Taille
	ft_printf("Taille: %i octets \n", sb.st_size);
	
	// Date de derniere modif
	ft_printf("Dernière modification: %s\n", ctime(&sb.st_mtime));
	
	return (0);
}
