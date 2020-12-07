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
	FILE *fp;
	char fileName[1024];

	if (!key || !folder)
		return (0);
	sprintf(fileName, "%s/%s", folder, "/key.pem");
	mkdir(folder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	fp = fopen(fileName, "w");
	if (PEM_write_ECPrivateKey(fp, key, NULL,
				   NULL, 0, NULL, NULL) == 0)
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	sprintf(fileName, "%s/%s", folder, "/key_pub.pem");
	fp = fopen(fileName, "w");
	if (PEM_write_EC_PUBKEY(fp, key) == 0)
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	return (1);
}
