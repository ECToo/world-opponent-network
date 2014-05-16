#include "PasswordDialog.h"

#include "WONGUI/GUIConfig.h"
#include "WONGUI/InputBox.h"

using namespace WONAPI;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
PasswordDialog::PasswordDialog()
{
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void PasswordDialog::InitComponent(ComponentInit &theInit)
{
	Dialog::InitComponent(theInit);
	if(theInit.mType==ComponentInitType_ComponentConfig)
	{
		ComponentConfigInit &anInit = (ComponentConfigInit&)theInit;
		ComponentConfig *aConfig = anInit.mConfig;
	
		WONComponentConfig_Get(aConfig,mPasswordInput,"PasswordInput");
		WONComponentConfig_Get(aConfig,mOkButton,"OkButton");
		WONComponentConfig_Get(aConfig,mCancelButton,"CancelButton");
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
const GUIString& PasswordDialog::GetPassword()
{
	return mPasswordInput->GetText();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void PasswordDialog::Reset()
{
	mPasswordInput->Clear(false);
	mPasswordInput->RequestFocus();
}