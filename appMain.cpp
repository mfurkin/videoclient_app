#include "appMain.h"
int main (int argc, char *argv[]) {
	HMODULE hDll = LoadLibrary("libvideoclient_dll.dll");
	if (hDll == NULL){
			std::wcout<<L"could not load client.dll error code="<<GetLastError()<<"\n";
	} else {
		SendRequestProc sendRequest = (SendRequestProc) GetProcAddress(hDll,"sendRequest");
		RepeatRequestProc repeatRequest = (RepeatRequestProc) GetProcAddress(hDll,"repeatError");
		ErrorsExistProc errorsExist = (ErrorsExistProc) GetProcAddress(hDll,"errorsExist");
		SaveStateProc  saveState = (SaveStateProc) GetProcAddress(hDll,"saveState");
		if ((sendRequest == NULL) || (repeatRequest == NULL) || (errorsExist == NULL) || (saveState == NULL))
			std::wcout<<L"Some functions could not be found in client library\n";
		else {
			if (argc == 1) {
				for (;errorsExist();)
					repeatRequest();
			} else
					if (argc != PARAMS_NUM)
						std::wcout<<L"Illegal parameters number\n";
					else {
						sendRequest(argv);
					}
			saveState();
		}
	}
	return 0;
}
