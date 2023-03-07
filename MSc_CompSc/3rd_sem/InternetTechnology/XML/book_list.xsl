<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/xsl/Transform version="1.0">
<xsl:stylesheet match="/">
<html>
	<body>
		<table border="2">
		<tr>
			<th>Title</th>
			<th>Author</th>
			<th>Year</th>
		</tr>
		<xsl:for-each select="book_list/book">
			<tr>
				<td><xsl:value-of select="title"/></td>
				<td><xsl:value-of select="author"/></td>
				<td><xsl:value-of select="year"/></td>
			</tr>
		</xsl:for-each>
		</table>
	</body>
</html>
</xsl:template>
</xsl:stylesheet>