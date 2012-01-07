<?xml version="1.0" ?> 
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output method="text" indent="yes" encoding="iso-8859-1" />
<!-- xsl file to generate setting CPP file for mfc project-->



<!-- FILE -->
<xsl:template match="file">
// <xsl:value-of select="name"/>.cpp
// implementation of  settings 
// Automatic generated header file by xml->xslt = header
<xsl:text>  &#10;</xsl:text>
#include &#60;Stdafx.h&#62;
#include "<xsl:value-of select="name"/>.h"
#include "win_type_global.h"
#include "regkey.h"

<!-- insert carriage return -->
<xsl:text>  &#10;&#10;&#10; </xsl:text>
<xsl:apply-templates select="class_settings"/>

</xsl:template> 


<!-- MAIN SETTING CLASS template -->
<xsl:template match="class_settings">

using namespace Space<xsl:value-of select="name"/>;

    <!-- istantiate global settings object-->
// global options object
<xsl:value-of select="name"/>  g_Options;
    <!-- string section key -->
<xsl:for-each select="//section">
static const char* lpsz<xsl:value-of select="name"/> = "<xsl:value-of select="name"/>";
    <!-- integer keys -->
        <!-- store the section name -->
    <xsl:variable name="namesect"><xsl:value-of select="name"/></xsl:variable>
    <xsl:for-each select="item_int">
static const char* lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/> = "<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>";
    </xsl:for-each>
    <xsl:for-each select="item_string">
static const char* lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/> = "<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>";
    </xsl:for-each>
</xsl:for-each>
    

//! constructor
<xsl:value-of select="name"/>::<xsl:value-of select="name"/>()
{

}

<!-- constructor of all sections -->
<xsl:variable name="parentclass"><xsl:value-of select="name"/></xsl:variable>
<xsl:for-each select="//section">
<xsl:value-of select="$parentclass"/>::<xsl:value-of select="name"/>::<xsl:value-of select="name"/>()
{
        <!-- integer initialization keys -->
        <!-- store the section name -->
    <xsl:for-each select="item_int">
    <xsl:value-of select="name"/> = <xsl:value-of select="default"/>;
    </xsl:for-each>
    <xsl:for-each select="item_string">
    <xsl:value-of select="name"/> = "<xsl:value-of select="default"/>";
    </xsl:for-each>
}

</xsl:for-each>

<!-- WRITEPROFILE -->
void Space<xsl:value-of select="name"/>::WriteProfile(const char* strKeyRoot)
{
    RegistryKey RegKey;
    LONG lRes;
    char buff[1024];

   
  <xsl:for-each select="//section">
    <xsl:variable name="namesect"><xsl:value-of select="name"/></xsl:variable>
    <xsl:variable name="sectobj"><xsl:value-of select="name_obj"/></xsl:variable>
    strcpy(buff, strKeyRoot);
    strcat(buff, "\\");
    strcat(buff, lpsz<xsl:value-of select="$namesect"/>);
    lRes = RegKey.Open(HKEY_CURRENT_USER, buff);  
    if (lRes)
    {
    	lRes = RegKey.Create(HKEY_CURRENT_USER, buff);
    }
    if (!lRes)
    {
	<xsl:for-each select="item_int">
        RegKey.setRegDWordValue(g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/>,lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>);
	</xsl:for-each>
	<xsl:for-each select="item_string">
        RegKey.setRegStringValue(g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/>.c_str(),  lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>);
	</xsl:for-each>
		RegKey.Close();
    }
  </xsl:for-each>
    
  
}

<!-- GETPROFILE -->
void Space<xsl:value-of select="name"/>::GetProfile(const char* strKeyRoot)
{
    RegistryKey RegKey;
    LONG lRes;
	char buff[1024];
	
    lRes = RegKey.Open(HKEY_CURRENT_USER, strKeyRoot);  
    if (!lRes)
    {
  <xsl:for-each select="//section">
        <xsl:variable name="namesect"><xsl:value-of select="name"/></xsl:variable>
        <xsl:variable name="sectobj"><xsl:value-of select="name_obj"/></xsl:variable>
        strcpy(buff, strKeyRoot);
        strcat(buff, "\\");
        strcat(buff, lpsz<xsl:value-of select="$namesect"/>);
        RegKey.Close();
        lRes = RegKey.Open(HKEY_CURRENT_USER, buff);  
        if (!lRes)
        {
    <xsl:for-each select="item_int">
           g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/> = RegKey.getRegDWordValue(<xsl:value-of select="default"/>, lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/> );
    </xsl:for-each>
    <xsl:for-each select="item_string">
           g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/> = RegKey.getRegStringValue("<xsl:value-of select="default"/>", lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>);
    </xsl:for-each>
        }
        else
        {
        	RegKey.Create(HKEY_CURRENT_USER, buff); 
        }
  </xsl:for-each>
    }
    else
    {
    	RegKey.Create(HKEY_CURRENT_USER, strKeyRoot); 
    }
    RegKey.Close();
}
</xsl:template> 

<!-- SECTION -->
<xsl:template match="section">
</xsl:template> 

<!-- item int -->
<xsl:template match="section/item_int">
</xsl:template> 

<!-- item string -->
<xsl:template match="section/item_string">
</xsl:template> 


<xsl:template match="section/name">
</xsl:template> 
<xsl:template match="section/name_obj">
</xsl:template> 

</xsl:stylesheet> 