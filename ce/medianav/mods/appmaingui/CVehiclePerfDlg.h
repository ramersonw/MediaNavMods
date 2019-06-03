#pragma once

#include "stdafx.h"
#include "glue.h"
#include "glue_other.h"
#include "utils.h"
#include "appmaingui.h"

class CVehiclePerfDlg : public CGUIFixedEmptyDlg<CVehiclePerfDlg>
{
public:
    CVehiclePerfDlg();
    virtual void createControls(CGUIEmptyDlg* pPrevDialog);
    virtual void initControls(CGUIEmptyDlg* pPrevDialog);
    virtual BOOL onBtnClick(DWORD controlID, ButtonClickType clickType);

    virtual BOOL onExit();
    virtual BOOL onTimer(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
    static const int cMeasureTimerID = 1100;
    static const wchar_t* cUndefResult;
    static const int cSpeedDisplayCount = 4;
    static const int cMaesureFlashCount = 5;
    
    CGUITextControl m_caption;
    CGUIImageControl m_headerLine;
//    CGUIImageControl m_dots[3];
    CGUITextControl  m_captions[7];
//    CGUITextControl  m_coloredCaptions[3];
    CGUITextControl  m_values[3];

    CGUITextControl  m_speed;
    CGUITextControl  m_time;

    CGUITextButtonControl m_resetButton;
    CGUIButtonControl m_backButton;

    DWORD   m_dwStartTime;
    int     m_prevSpeed;

    bool m_b60Got;
    bool m_b80Got;
    bool m_b100Got;

    int m_speedDisplayCounter;
    int m_measureFlashCounter;

    void startMeasure();
    void stopMeasure();
    void setSpeedText(DWORD speed);
};
template class CGUIFixedEmptyDlg<CVehiclePerfDlg>;
