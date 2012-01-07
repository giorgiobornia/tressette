<?xml version="1.0" ?> 
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output method="text" indent="yes" encoding="iso-8859-1" />
<!-- xsl file to generate setting HEADER file for mfc project-->

<!-- FILE -->
<xsl:template match="file">
// <xsl:value-of select="name"/>.h 
// used to handle settings 
// Automatic generated header file by xml->xslt = header

#ifndef   <xsl:value-of select="name_define"/>
#define   <xsl:value-of select="name_define"/>
<!-- insert carriage returns-->
<xsl:text>  &#10; &#10;&#10;</xsl:text>

#include &#60;string&#62;


<!-- use namespace to group functions that operate on settings -->
namespace Space<xsl:value-of select="class_settings/name"/>
{
<xsl:apply-templates select="class_settings"/>

    //! write settings in the registry
    void    WriteProfile(const char* strKeyRoot);
    //! retrieves setting from the registry
    void    GetProfile(const char* strKeyRoot);
    
    
};//end namespace

extern Space<xsl:value-of select="class_settings/name"/>::<xsl:value-of select="class_settings/name"/> g_Options;

#endif
</xsl:template> 


<!-- MAIN CLASS template -->
<xsl:template match="class_settings">
//! class <xsl:value-of select="name"/>
class <xsl:value-of select="name"/>
{
public:
    <!-- constructor -->
    <xsl:value-of select="name"/>();
    <!-- sub class section -->
    <xsl:apply-templates select="section"/>

};

</xsl:template> 

<!-- SECTION subclass-->
<xsl:template match="section">
    class <xsl:value-of select="name"/>
    {
        public:
            <xsl:value-of select="name"/>();
              <xsl:for-each select="item_int">
            //! <xsl:value-of select="comment"/>
            int <xsl:value-of select="name"/>;
              </xsl:for-each>
              <xsl:for-each select="item_string">
            //! <xsl:value-of select="comment"/>
            std::string <xsl:value-of select="name"/>;
              </xsl:for-each>
    };
    <!-- methods -->
    
    <!-- object instance -->
public:
    <xsl:value-of select="name"/><xsl:text>&#32;</xsl:text>  <xsl:value-of select="name_obj"/>;
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