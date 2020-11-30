#include "hblk_crypto.h"

/**
 * ec_save - Saves an existing EC key pair on the disk
 * @key: EC key pair to be saved on disk
 * @folder: path to the folder in which to save the keys
 *
 * Return: 1 on success, 0 else
 **/
int ec_save(EC_KEY *key, char const *folder)
{
	FILE *privK = 0, *pubK = 0;

	privK = fopen("./", strcat(folder, "/key.pem")),"w+");
	pubK = fopen(strcat("./", strcat(folder, "/key_pub.pem")),"w+");
	PEM_write_PrivateKey(privK, key, NULL,
			       NULL, EC_PUB_LEN, NULL, NULL);
	fclose(privK);
	fclose(pubK);
	return (1);
}
