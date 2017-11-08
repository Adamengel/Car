#include "LicenceNumber.h"

int licenseNumber::s_license = 10000001;
int licenseNumber::getNextLicense()
{
	return s_license++;
}
