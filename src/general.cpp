#include "general.h"
#include "utils.h"

Napi::Boolean wrap_vJoyEnabled(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	bool enabled = vJoyEnabled();

	return Napi::Boolean::New(env, enabled);
}

Napi::Number wrap_GetvJoyVersion(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	short version = GetvJoyVersion();

	return Napi::Number::New(env, (double)version);
}

Napi::String wrap_GetvJoyProductString(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	PVOID p_prodString = GetvJoyProductString();

	std::string prodString = utf8_encode((PWSTR)p_prodString);

	CoTaskMemFree(p_prodString);

	return Napi::String::New(env, prodString);
}

Napi::String wrap_GetvJoyManufacturerString(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	PVOID p_manuString = GetvJoyManufacturerString();

	std::string manuString = utf8_encode((PWSTR)p_manuString);

	CoTaskMemFree(p_manuString);

	return Napi::String::New(env, manuString);
}

Napi::String wrap_GetvJoySerialNumberString(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	PVOID p_serialString = GetvJoySerialNumberString();

	std::string serialString = utf8_encode((PWSTR)p_serialString);

	CoTaskMemFree(p_serialString);

	return Napi::String::New(env, serialString);
}

Napi::Object wrap_DriverMatch(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	WORD DllVersion;
	WORD DrvVersion;

	bool matches = DriverMatch(&DllVersion, &DrvVersion);

	Napi::Boolean var_matches = Napi::Boolean::New(env, matches);
	Napi::Number var_dllversion = Napi::Number::New(env, (double)DllVersion);
	Napi::Number var_drvversion = Napi::Number::New(env, (double)DrvVersion);

	Napi::Object res = Napi::Object::New(env);

	res.Set("matches", var_matches);
	res.Set("dll_version", var_dllversion);
	res.Set("drv_version", var_drvversion);

	return res;
}

Napi::Number wrap_GetvJoyMaxDevices(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	int maxDevices;

	GetvJoyMaxDevices(&maxDevices);

	return Napi::Number::New(env, (double)maxDevices);
}

Napi::Number wrap_GetNumberExistingVJD(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	int existingVJD;

	GetNumberExistingVJD(&existingVJD);

	return Napi::Number::New(env, (double)existingVJD);
}