#include "hblk_crypto.h"

/**
 * ec_load - Loads an existing EC key pair from the disk
 * @folder: path to the folder in which the key is saved
 *
 * Return: pointer to the EC_KEY structure
 **/
EC_KEY *ec_load(char const *folder)
{
	FILE *fp;
	char fileName[1024];
	EC_KEY *key = 0;

	if (!folder)
		return (0);
	sprintf(fileName, "%s/%s", folder, "/key.pem");
	fp = fopen(fileName, "r");
	if (PEM_read_ECPrivateKey(fp, &key, NULL, NULL) == 0)
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	sprintf(fileName, "%s/%s", folder, "/key_pub.pem");
	fp = fopen(fileName, "r");
	if (PEM_read_EC_PUBKEY(fp, &key, 0, 0) == 0)
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	return (key);
}
