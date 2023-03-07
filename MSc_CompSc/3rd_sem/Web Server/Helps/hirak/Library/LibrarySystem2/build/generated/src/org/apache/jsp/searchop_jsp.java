package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class searchop_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.Vector _jspx_dependants;

  private org.apache.jasper.runtime.ResourceInjector _jspx_resourceInjector;

  public Object getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.apache.jasper.runtime.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\n");
      out.write("   \"http://www.w3.org/TR/html4/loose.dtd\">\n");
      out.write("\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("        <title>Search Page</title>\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        <h1><center><u>Library Automation System</u></center></h1>\n");
      out.write("        <center>\n");
      out.write("        <table border=\"1\">\n");
      out.write("            <thead>\n");
      out.write("                <tr>\n");
      out.write("                    <th><h2>Resource ID</h2></th>\n");
      out.write("                    <th><h2>Name</h2></th>\n");
      out.write("                    <th><h2>Type</h2></th>\n");
      out.write("                    <th><h2>Author's Name</h2></th>\n");
      out.write("                    <th><h2>Category</h2></th>\n");
      out.write("                    <th><h2>No of Copies</h2></th>\n");
      out.write("                    <th><h2>Available</h2></th>\n");
      out.write("                </tr>\n");
      out.write("            </thead>\n");
      out.write("            <tbody>\n");
      out.write("                <tr>\n");
      out.write("                    <td>1</td>\n");
      out.write("                    <td>The Da Vinci Code</td>\n");
      out.write("                    <td>Book</td>\n");
      out.write("                    <td>Dan Brown</td>\n");
      out.write("                    <td>Thriller</td>\n");
      out.write("                    <td>7</td>\n");
      out.write("                    <td>4</td>\n");
      out.write("                </tr>\n");
      out.write("                <tr>\n");
      out.write("                    <td>2</td>\n");
      out.write("                    <td>Digital Fortress</td>\n");
      out.write("                    <td>Book</td>\n");
      out.write("                    <td>Dan Brown</td>\n");
      out.write("                    <td>Thriller</td>\n");
      out.write("                    <td>6</td>\n");
      out.write("                    <td>2</td>\n");
      out.write("                </tr>\n");
      out.write("                <tr>\n");
      out.write("                    <td>3</td>\n");
      out.write("                    <td>The Lost Symbols</td>\n");
      out.write("                    <td>Book</td>\n");
      out.write("                    <td>Dan Brown</td>\n");
      out.write("                    <td>Thriller</td>\n");
      out.write("                    <td>7</td>\n");
      out.write("                    <td>3</td>\n");
      out.write("                </tr>\n");
      out.write("               \n");
      out.write("            </tbody>\n");
      out.write("        </table>\n");
      out.write("        </center>\n");
      out.write("        <hr>\n");
      out.write("        <center>\n");
      out.write("            <h1><u>Enter the details of the Resource to Select</u></h1>\n");
      out.write("            <table border=\"0\">\n");
      out.write("                <thead>\n");
      out.write("                    <tr>\n");
      out.write("                        <th></th>\n");
      out.write("                        <th></th>\n");
      out.write("                    </tr>\n");
      out.write("                </thead>\n");
      out.write("                <tbody>\n");
      out.write("                    <tr>\n");
      out.write("                        <td><h3>Checkout ID :</h3></td>\n");
      out.write("                        <td><input type=\"text\" name=\"cid\" value=\"\" /></td>\n");
      out.write("                    </tr>\n");
      out.write("                    <tr>\n");
      out.write("                        <td><h3>Member ID :</h3></td>\n");
      out.write("                        <td><input type=\"text\" name=\"member\" value=\"\" /></td>\n");
      out.write("                    </tr>\n");
      out.write("                    <tr>\n");
      out.write("                        <td><h3>Resource ID :</h3></td>\n");
      out.write("                        <td><input type=\"text\" name=\"resource\" value=\"\" /></td>\n");
      out.write("                    </tr>\n");
      out.write("                    <tr>\n");
      out.write("                        <td><h3>Borrow Date :</h3></td>\n");
      out.write("                        <td><input type=\"text\" name=\"borrow_dt\" value=\"\" />(dd-mon-yy)</td>\n");
      out.write("                    </tr>\n");
      out.write("                    <tr>\n");
      out.write("                        <td><h3>Return Date :</h3></td>\n");
      out.write("                        <td><input type=\"text\" name=\"return_dt\" value=\"\" />(dd-mon-yy)</td>\n");
      out.write("                    </tr>\n");
      out.write("                    <tr>\n");
      out.write("                        <td colspan=\"2\"><center><input type=\"submit\" value=\"Submit\" name=\"Submit\" /></center></td>\n");
      out.write("                    </tr>\n");
      out.write("\n");
      out.write("                </tbody>\n");
      out.write("            </table>\n");
      out.write("\n");
      out.write("        </center>\n");
      out.write("    </body>\n");
      out.write("</html>\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
