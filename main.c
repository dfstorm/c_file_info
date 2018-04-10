
#include "libft.h"
#include <sys/stat.h> 	// file info
#include <time.h> 		// time formating
#include <dirent.h> 	// dir access
#include <sys/types.h> 	// type constant
#include <pwd.h> 		// user info
#include <grp.h>		// Group info

int		main(int argc, char **argv)
{
	struct stat sb; 
	struct passwd *pwd;
	struct group *grp;
	
	if(argc || argv) {}

	stat("test.txt", &sb);

	// nom
	ft_printf("Nom: test.txt\n"); // Remplacer lors de listing de dir ... ?
	
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
	ft_printf("Mode: %lo\n", sb.st_mode);
	
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
	ft_printf("st_ctime: %s\n", ctime(&sb.st_mtime));
	
	return (0);
}
