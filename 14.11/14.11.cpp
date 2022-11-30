#include <windows.h>
#include <windowsX.h>
#include <tchar.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hButtonGasStation, hButtonCafe, hEditPetrol, hListPetrol, hAmountPetrol, hSum, hSum1, hSum2;
HWND hEdit1, hEdit2, hEdit3, hEdit4, hEdit5, hEdit6;
HWND hCheck1, hCheck2, hCheck3, hCheck4, hCheck5, hCheck6;
TCHAR str[50];
TCHAR buf[50];
TCHAR text[100];

double sum = 0;


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

void ListPetrol() {
	int index = SendMessage(hListPetrol, LB_GETCURSEL, 0, 0);
	if (index != LB_ERR) {
		index += 1;
		switch (index) {
		case 1:
			SendMessage(hEditPetrol, WM_SETTEXT, 0, LPARAM(TEXT("1.73")));
			break;
		case 2:
			SendMessage(hEditPetrol, WM_SETTEXT, 0, LPARAM(TEXT("1.93")));
			break;
		case 3:
			SendMessage(hEditPetrol, WM_SETTEXT, 0, LPARAM(TEXT("2")));
			break;
		}
	}
}

void CheckBox() {
	LRESULT check1 = SendMessage(hCheck1, BM_GETCHECK, 0, 0);
	LRESULT check2 = SendMessage(hCheck2, BM_GETCHECK, 0, 0);
	LRESULT check3 = SendMessage(hCheck3, BM_GETCHECK, 0, 0);
	LRESULT check4 = SendMessage(hCheck4, BM_GETCHECK, 0, 0);
	LRESULT check5 = SendMessage(hCheck5, BM_GETCHECK, 0, 0);
	LRESULT check6 = SendMessage(hCheck6, BM_GETCHECK, 0, 0);

	if (check1 == BST_CHECKED) {
		sum += 3.50;
	}
	else if (check2 == BST_CHECKED) {
		sum += 3;
	}
	else if (check3 == BST_CHECKED) {
		sum += 2.50;
	}
	else if (check4 == BST_CHECKED) {
		sum += 1.50;
	}
	else if (check5 == BST_CHECKED) {
		sum += 1;
	}
	else if (check6 == BST_CHECKED) {
		sum += 1;
	}

	wsprintf(buf, TEXT("%d"), int(sum));
	SendMessage(hSum2, WM_SETTEXT, 0, LPARAM(buf));
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG: {
		hButtonGasStation = GetDlgItem(hWnd, IDC_BUTTON1);
		hButtonCafe = GetDlgItem(hWnd, IDC_BUTTON2);
		hEditPetrol = GetDlgItem(hWnd, IDC_EDIT13);
		hListPetrol = GetDlgItem(hWnd, IDC_LIST1);
		hAmountPetrol = GetDlgItem(hWnd, IDC_EDIT3);
		hSum = GetDlgItem(hWnd, IDC_EDITSUMM1);
		hSum1 = GetDlgItem(hWnd, IDC_EDITSUMM2);
		hSum2 = GetDlgItem(hWnd, IDC_EDITSUMM3);

		hCheck1 = GetDlgItem(hWnd, IDC_CHECK1);
		hCheck2 = GetDlgItem(hWnd, IDC_CHECK2);
		hCheck3 = GetDlgItem(hWnd, IDC_CHECK3);
		hCheck4 = GetDlgItem(hWnd, IDC_CHECK4);
		hCheck5 = GetDlgItem(hWnd, IDC_CHECK5);
		hCheck6 = GetDlgItem(hWnd, IDC_CHECK6);

		hEdit1 = GetDlgItem(hWnd, IDC_EDIT1);
		hEdit2 = GetDlgItem(hWnd, IDC_EDIT5);
		hEdit3 = GetDlgItem(hWnd, IDC_EDIT6);
		hEdit4 = GetDlgItem(hWnd, IDC_EDIT7);
		hEdit5 = GetDlgItem(hWnd, IDC_EDIT8);
		hEdit6 = GetDlgItem(hWnd, IDC_EDIT9);

		SendMessage(hEdit1, WM_SETTEXT, 0, LPARAM(TEXT("3.50")));
		SendMessage(hEdit2, WM_SETTEXT, 0, LPARAM(TEXT("3.00")));
		SendMessage(hEdit3, WM_SETTEXT, 0, LPARAM(TEXT("2.50")));
		SendMessage(hEdit4, WM_SETTEXT, 0, LPARAM(TEXT("1.50")));
		SendMessage(hEdit5, WM_SETTEXT, 0, LPARAM(TEXT("1.00")));
		SendMessage(hEdit6, WM_SETTEXT, 0, LPARAM(TEXT("1.00")));

		SendMessage(hListPetrol, LB_ADDSTRING, 0, LPARAM(TEXT("95 Euro")));
		SendMessage(hListPetrol, LB_ADDSTRING, 0, LPARAM(TEXT("95 Premium")));
		SendMessage(hListPetrol, LB_ADDSTRING, 0, LPARAM(TEXT("Diesel")));
	}
					  break;

	case WM_COMMAND: {
		if (LOWORD(wParam) == IDC_BUTTON1) {
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DLGPROC(DlgProc));
		}
		if (LOWORD(wParam) == IDC_LIST1) {
			ListPetrol();
		}
		if (LOWORD(wParam) == IDC_RADIO1 && IDC_EDIT3 != NULL) {
			int amount = GetWindowTextLength(hAmountPetrol);
			GetDlgItemText(hWnd, IDC_EDIT3, str, amount + 1);
			SendMessage(hSum1, WM_SETTEXT, 0, LPARAM(str));
		}
		if (LOWORD(wParam) == IDC_RADIO2 && IDC_EDIT4 != NULL) {
			int amount = GetWindowTextLength(hAmountPetrol);
			GetDlgItemText(hWnd, IDC_EDIT4, str, amount + 1);
			SendMessage(hSum1, WM_SETTEXT, 0, LPARAM(str));
		}

		if (LOWORD(wParam) == IDC_BUTTON2) {
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hWnd, DLGPROC(DlgProc));
		}
		if (LOWORD(wParam) == IDC_CHECK1) {
			CheckBox();
		}
		if (LOWORD(wParam) == IDC_CHECK2) {
			CheckBox();
		}
		if (LOWORD(wParam) == IDC_CHECK3) {
			CheckBox();
		}
		if (LOWORD(wParam) == IDC_CHECK4) {
			CheckBox();
		}
		if (LOWORD(wParam) == IDC_CHECK5) {
			CheckBox();
		}
		if (LOWORD(wParam) == IDC_CHECK6) {
			CheckBox();
		}
		if (IDD_DIALOG3) {
			TCHAR buffer[200];
			GetWindowText(hSum2, buffer, 200);
			wcscpy_s(text, buffer);
		}
		if (LOWORD(wParam) == IDC_BUTTON1) {
			EndDialog(hWnd, 0);
			HWND hParent = GetParent(hWnd);
			SendMessage(hParent, WM_SETTEXT, 0, LPARAM(buf));
		}
		if (LOWORD(wParam) == IDC_BUTTON2) {
			EndDialog(hWnd, 0);
			HWND hParent = GetParent(hWnd);
			SendMessage(hParent, WM_SETTEXT, 0, LPARAM(str));
		}
	}
				   break;

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;
	}
	return FALSE;
}