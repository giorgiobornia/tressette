<?xml version="1.0" ?> 
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output method="text" indent="yes" encoding="iso-8859-1" />
<!-- xsl file to generate languages class-->

<!-- FILE -->
<xsl:template match="file">
// <xsl:value-of select="name"/>.h 
// used to handle languages resource 
// Automatic generated header file by xml->xslt = header

#ifndef   <xsl:value-of select="name_define"/>
#define   <xsl:value-of select="name_define"/>
<!-- insert carriage returns-->
<xsl:text>  &#10; &#10;&#10;</xsl:text>

#include &#60;string&#62;

<xsl:apply-templates select="class_languag"/>

</xsl:template> 


<!-- MAIN CLASS template -->
<xsl:template match="class_languag">
//! class <xsl:value-of select="name"/>
class <xsl:value-of select="name"/>
{
protected:
	<!-- constructor -->
    <xsl:value-of select="name"/>();
   
public:
	static  <xsl:value-of select="name"/>* Instance();
	
private:
    static <xsl:value-of select="name"/>* pinstance;
   
public:
    
    enum eLangId
    {
    <!-- enum all languages id -->
    	<xsl:apply-templates select="lan_names"/>
    	TOT_LANG // it mus be  always on the last place
    };
    enum eStringID
    {
        <xsl:apply-templates select="string_det"/>
        TOT_STRINGS // it mus be always on the last place
    };
    
public:
    void  SetLang(eLangId eVal){m_eLangid = eVal;}
    eLangId  GetLang(){return m_eLangid ;}
    std::string  GetStringId(eStringID eId);
    char*        GetCStringId(eStringID eId);

private:
    eLangId      m_eLangid;
    std::string  m_matStringsLang[TOT_LANG][TOT_STRINGS];

};

#endif

</xsl:template> 

<!-- template lan_names -->
<xsl:template match="lan_names">

<xsl:for-each select="item_lan">
<xsl:choose>
		<xsl:when test="position()=1">
<xsl:text>&#09;</xsl:text><xsl:value-of select="ID"/>=0,
        </xsl:when>
		<xsl:otherwise>
<xsl:text>&#09;&#09;</xsl:text><xsl:value-of select="ID"/>,
        </xsl:otherwise>
</xsl:choose> 
</xsl:for-each>
</xsl:template>

<!-- template lan_names -->
<xsl:template match="string_det">
<xsl:for-each select="item_s">
<xsl:choose>
		<xsl:when test="position()=1">
<xsl:text>&#09;</xsl:text><xsl:value-of select="ID"/>=0,
        </xsl:when>
		<xsl:otherwise>
<xsl:text>&#09;&#09;</xsl:text><xsl:value-of select="ID"/>,
        </xsl:otherwise>
</xsl:choose> 
</xsl:for-each>
</xsl:template>

</xsl:stylesheet> 