#include "resource.h"

#define _WIN32_WINNT 0x0400

#include <windows.h>
#include <tchar.h>
#include <windowsx.h>
#include <commctrl.h>

#include "udialogx.h"
#include "ubutton.h"
#include "udlgapp.h"
#include "colors.h"
#include "umsg.h"
#include "ubitmap.h"

#include "cool_button.h"
#include "imagebutton.h"

using huys::UDialogBox;

class UDialogExt : public UDialogBox
{
    enum {
        IDC_BUTTON_UE = 3333,
        IDC_BUTTON_CHECK = 3334,
        IDC_BUTTON_RA = 3335,
        IDC_BUTTON_RA2 = 3336,
        IDC_GROUPBOX = 3337,
        IDC_ICONBUTTON = 3338,
        IDC_BN_OWNERDRAWN = 4111,
        IDC_BN_ICONTEXT = 4333,
        IDC_BN_COOL = 4335,
        IDC_BN_BITMAP = 4336
    };
public:
    UDialogExt(HINSTANCE hInst, UINT nID)
    : UDialogBox(hInst, nID),
      m_pBtn(0),
      m_pCheckBtn(0),
      m_pRadioBtn1(0),
      m_pRadioBtn2(0),
      m_pGroupBox(0),
      m_pIconBtn(0),
      m_pOwnerDrawnBtn(0),
      m_pIconTextBtn(0),
      m_pCoolBtn(0),
      m_pImageBtn(0)
    {}

    ~UDialogExt()
    {
        CHECK_PTR(m_pBtn);
        CHECK_PTR(m_pCheckBtn);
        CHECK_PTR(m_pRadioBtn1);
        CHECK_PTR(m_pRadioBtn2);
        CHECK_PTR(m_pGroupBox);
        CHECK_PTR(m_pIconBtn);
        CHECK_PTR(m_pOwnerDrawnBtn);
        CHECK_PTR(m_pIconTextBtn);
        CHECK_PTR(m_pCoolBtn);
        CHECK_PTR(m_pImageBtn);
    }

    virtual BOOL onInit()
    {
        //hIcon = LoadIcon(hInst, MAKEINTRESOURCE(nResID));
        m_hIcon = (HICON)LoadImage( m_hInst, // small class icon
            MAKEINTRESOURCE(IDI_APP),
            IMAGE_ICON,
            GetSystemMetrics(SM_CXSMICON)*2,
            GetSystemMetrics(SM_CYSMICON)*2,
            LR_DEFAULTCOLOR );


        RECT rcRa = {250, 190, 350, 290};
        RECT rcRa2 = {420, 190, 520, 290};
        RECT rcIco = {5, 200, 115, 300};
        RECT rcOD = {460, 70, 560, 150};
        RECT rcGB = {220, 20, 650, 300};
        RECT rcCH = {250, 50, 350, 150};
        RECT rcIT = {10, 310, 210, 410};
        RECT rcTest = {10, 20, 110, 160};

        RECT rcCool = {250, 350, 450, 410};

        m_pBtn = new UButton(m_hDlg, IDC_BUTTON_UE, m_hInst);
        m_pBtn->create();
        m_pBtn->setWindowText(_T("help"));
        m_pBtn->setPosition(&rcTest);

        m_pCheckBtn = new UCheckButton(m_hDlg, IDC_BUTTON_CHECK, m_hInst);
        m_pCheckBtn->create();
        m_pCheckBtn->setWindowText(_T("Check me"));
        m_pCheckBtn->setPosition(&rcCH);

        m_pRadioBtn1 = new URadioButton(m_hDlg, IDC_BUTTON_RA, m_hInst);
        m_pRadioBtn1->create();
        m_pRadioBtn1->setWindowText(_T("Radio me"));
        m_pRadioBtn1->setPosition(&rcRa);

        m_pRadioBtn2 = new URadioButton(m_hDlg, IDC_BUTTON_RA2, m_hInst);
        m_pRadioBtn2->create();
        m_pRadioBtn2->setWindowText(_T("Radio you"));
        m_pRadioBtn2->setPosition(&rcRa2);

        m_pGroupBox = new UGroupBox(m_hDlg, IDC_GROUPBOX, m_hInst);
        m_pGroupBox->create();
        m_pGroupBox->setPosition(&rcGB);

        m_pIconBtn = new UIconButton(m_hDlg, IDC_ICONBUTTON, m_hInst);
        m_pIconBtn->create();
        m_pIconBtn->setWindowText(_T("Icon"));
        m_pIconBtn->setIcon(m_hIcon);
        m_pIconBtn->setPosition(&rcIco);


        m_pOwnerDrawnBtn = new UOwnerDrawnButton(m_hDlg, IDC_BN_OWNERDRAWN, m_hInst);
        m_pOwnerDrawnBtn->create();
        m_pOwnerDrawnBtn->setPosition(&rcOD);


        m_pIconTextBtn = new UIconTextButton(m_hDlg, IDC_BN_ICONTEXT, m_hInst);

        m_pCoolBtn = new UCoolButton(m_hDlg, IDC_BN_COOL, m_hInst);
        m_pCoolBtn->attachBitmap();
        m_pCoolBtn->create();
        m_pCoolBtn->setBtnPos(rcCool.left, rcCool.top);

        m_pImageBtn = new UImageButton(m_hDlg, IDC_BN_BITMAP, m_hInst);
        m_pImageBtn->setPos(380, 310, 360, 100);
        m_pImageBtn->setTextColor(huys::blue);
        m_pImageBtn->setAlignMode(UImageButton::TEXT_INCLUDE | UImageButton::IMAGE_RIGHT | UImageButton::IMAGE_VCENTER);
        m_pImageBtn->create();
        m_pImageBtn->setWindowText(_T("�Ұ���"));
        m_pImageBtn->setButtomImage(IDB_IMAGE, huys::magenta);
        return TRUE;
    }

    virtual BOOL onCommand(WPARAM wParam, LPARAM lParam)
    {
        RECT rcIT = {10, 310, 210, 410};
        switch (LOWORD (wParam))
        {
            case IDC_BUTTON_UE:
                showCustomInfoMsg("You Press me!", m_hDlg);
                //::MessageBox(hDlg, "xx", "xx", MB_OK);
                return TRUE;
            case IDC_BUTTON_CHECK:
                showCustomInfoMsg("Check me!", m_hDlg);
                if (IsDlgButtonChecked(m_hDlg, IDC_BUTTON_CHECK))
                {
                    m_pBtn->disable();
                }
                else
                {
                    m_pBtn->enable();
                }
                return TRUE;
            case IDC_BUTTON_RA:
                {
                    m_pImageBtn->enable();
                }
                return TRUE;
            case IDC_BUTTON_RA2:
                {
                    m_pImageBtn->disable();
                }
                return TRUE;
            case IDC_ICONBUTTON:
                //showCustomInfoMsg("Icon here!", m_hDlg);
                return TRUE;
            case IDC_BN_OWNERDRAWN:
                //showCustomInfoMsg("Hello Owner!", m_hDlg);
                {
                    if (NULL == m_pIconTextBtn->getHWND())
                    {
                        m_pIconTextBtn->create();
                        m_pIconTextBtn->setPosition(&rcIT);
                        m_pIconTextBtn->setIcon(m_hIcon);
                        m_pIconTextBtn->setWindowText(_T("IT"));
                    //m_pIconTextBtn->subclassProc();
                    }
                }
                return TRUE;
            case IDC_BN_COOL:
                showMsg("Cool!", "hi", m_hDlg);
                return TRUE;
            case IDC_BN_BITMAP:
                return this->onBnImage();
            case IDOK :
                m_pBtn->setWindowText(_T("New Text"));
                return TRUE;
        default:
            return UDialogBox::onCommand(wParam, lParam);
        }
    }
private:
    UButton *m_pBtn;
    UCheckButton *m_pCheckBtn;
    URadioButton *m_pRadioBtn1;
    URadioButton *m_pRadioBtn2;
    UGroupBox *m_pGroupBox;
    UIconButton *m_pIconBtn;
    UOwnerDrawnButton *m_pOwnerDrawnBtn;
    UIconTextButton *m_pIconTextBtn;
    HICON m_hIcon;

    UCoolButton *m_pCoolBtn;
    UImageButton *m_pImageBtn;
private:
    BOOL onBnImage()
    {
        static BOOL bFlag = FALSE;
        if (!bFlag)
        {
            m_pImageBtn->setAlignMode(UImageButton::TEXT_INCLUDE | UImageButton::IMAGE_VCENTER);
        }
        else
        {
            m_pImageBtn->setAlignMode(UImageButton::TEXT_INCLUDE | UImageButton::IMAGE_RIGHT | UImageButton::IMAGE_VCENTER);
        }
        bFlag = !bFlag;
        m_pImageBtn->reset();
        return FALSE;
    }
};

UDLGAPP_T(UDialogExt, IDD_TEST);

