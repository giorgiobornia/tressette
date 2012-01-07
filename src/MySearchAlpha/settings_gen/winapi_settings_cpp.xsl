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
<!-- #include &#60;Stdafx.h&#62; -->
#include "StdAfx.h"
#include "win_type_global.h"
#include "<xsl:value-of select="name"/>.h"


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


void Space<xsl:value-of select="name"/>::WriteProfile(const char* strIniFileName)
{
   char buff[2048];
	buff[0] = '\0';
   
  <xsl:for-each select="//section">
        <xsl:variable name="namesect"><xsl:value-of select="name"/></xsl:variable>
        <xsl:variable name="sectobj"><xsl:value-of select="name_obj"/></xsl:variable>
    <xsl:for-each select="item_int">
    sprintf(buff,"%d",g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/>);     
    WritePrivateProfileString(lpsz<xsl:value-of select="$namesect"/>, lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>, buff,strIniFileName);
    </xsl:for-each>
    <xsl:for-each select="item_string">
    WritePrivateProfileString(lpsz<xsl:value-of select="$namesect"/>, lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>, g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/>.c_str(),strIniFileName);
    </xsl:for-each>
  </xsl:for-each>
    
  
}

void Space<xsl:value-of select="name"/>::GetProfile(const char* strIniFileName)
{
  char buff[2048];
  <xsl:for-each select="//section">
        <xsl:variable name="namesect"><xsl:value-of select="name"/></xsl:variable>
        <xsl:variable name="sectobj"><xsl:value-of select="name_obj"/></xsl:variable>
    <xsl:for-each select="item_int">
    g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/> = GetPrivateProfileInt(lpsz<xsl:value-of select="$namesect"/>, lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>, <xsl:value-of select="default"/>,strIniFileName);
    </xsl:for-each>
    <xsl:for-each select="item_string">
    GetPrivateProfileString(lpsz<xsl:value-of select="$namesect"/>, lpsz<xsl:value-of select="$namesect"/><xsl:value-of select="name"/>, "<xsl:value-of select="default"/>",buff, 2048,strIniFileName);
    g_Options.<xsl:value-of select="$sectobj"/>.<xsl:value-of select="name"/> = buff;
    </xsl:for-each>
  </xsl:for-each>
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