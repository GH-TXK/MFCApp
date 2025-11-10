#pragma once


// MyCButton

class MyCButton : public CButton
{
	DECLARE_DYNAMIC(MyCButton)

public:
	MyCButton();
	virtual ~MyCButton();
	MyCButton* m_CButton;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


