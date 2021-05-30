#include <Windows.h>

static LPSTR prevLang = (LPSTR)calloc(KL_NAMELENGTH, sizeof LPSTR);

bool switchEnglishInputMethod()
{
	LPSTR currentLang = (LPSTR)malloc(KL_NAMELENGTH);
	if (currentLang == NULL) {
		return false;
	}
	GetKeyboardLayoutNameA(currentLang);

	LRESULT result = SendMessageA(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 0, LPARAM(LoadKeyboardLayoutA("00000409", KLF_ACTIVATE)));

	strcpy_s(prevLang, KL_NAMELENGTH, currentLang);

	free(currentLang);

	return result == 0;
}


bool restorePreviousInputMethod() {
	if (strlen(prevLang) == 0) {
		return false;
	}
	LRESULT result = SendMessageA(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 0, LPARAM(LoadKeyboardLayoutA(prevLang, KLF_ACTIVATE)));
	return result == 0;
}
