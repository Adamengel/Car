#pragma once

static class licenseNumber
{

public:
	static int getNextLicense();

private:
	static int s_license;
};