#include "LanNameDialog.h"

#include "WONGUI/GUIConfig.h"
#include "WONGUI/InputBox.h"


using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
LanNameDialog::LanNameDialog()
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
LanNameDialog::~LanNameDialog()
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanNameDialog::InitComponent(ComponentInit &theInit)
{
	Dialog::InitComponent(theInit);
	if(theInit.mType==ComponentInitType_ComponentConfig)
	{
		ComponentConfigInit &anInit = (ComponentConfigInit&)theInit;
		ComponentConfig *aConfig = anInit.mConfig;

		WONComponentConfig_Get(aConfig,mNameInput,"LanNameInput");
		WONComponentConfig_Get(aConfig,mOkButton,"OkButton");
		WONComponentConfig_Get(aConfig,mCancelButton,"CancelButton");
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void LanNameDialog::Reset()
{
	mNameInput->Clear(false);
	mNameInput->RequestFocus();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
const GUIString& LanNameDialog::GetName()
{
	return mNameInput->GetText();
}
