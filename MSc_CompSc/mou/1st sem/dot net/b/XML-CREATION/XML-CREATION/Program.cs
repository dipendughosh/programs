using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace XML_CREATION
{
    class Program
    {
        static void Main(string[] args)
        {
            //Create the XmlDocument.
            XmlDocument doc = new XmlDocument();
            XmlNode node;
            XmlElement root;
            XmlElement book_child1;
            XmlElement book_child2;
            XmlElement book_child3;
            XmlElement book_child4;
            XmlAttribute attribute;
            XmlAttribute attribute1;

            //Creating the Xml versioning tag.
            node = doc.CreateNode(XmlNodeType.XmlDeclaration, "", "");
            doc.AppendChild(node);  
           
            //Root Element and its attribute creation.
            root = doc.CreateElement("", "Book", "");
            attribute = doc.CreateAttribute("Book-id");
            attribute.Value = "1234";
            attribute1 = doc.CreateAttribute("Book-Version-No.");
            attribute1.Value = "550-ABC-01";

            //Child Element Creation.            
            book_child1 = doc.CreateElement("", "Title", "");
            book_child1.InnerText = "Angel Divine";

            book_child2 = doc.CreateElement("", "Author", "");
            book_child2.InnerText = "Candela Wings";

            book_child3 = doc.CreateElement("", "Published-Date", "");
            book_child3.InnerText = "10-02-1994";

            book_child4 = doc.CreateElement("", "ISBN", "");
            book_child4.InnerText = "GC9830";

            //Attachment
            book_child2.AppendChild(book_child1);
            book_child2.AppendChild(book_child3);

            book_child2.AppendChild(book_child1);
            book_child1.AppendChild(book_child3);
            book_child1.AppendChild(book_child4);

            root.AppendChild(book_child1);

            doc.AppendChild(root);
            doc.DocumentElement.SetAttributeNode(attribute);
            doc.DocumentElement.SetAttributeNode(attribute1);

            //Save the document to a file.
            try
            {
                doc.Save("C:\\First-File.Xml");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Source);
            }
            //You can also use Save method to display contents on console 
            //if you pass Console.Out as a 
            //parameter. For example: 
            //doc.Save(Console.Out); 
        }
    }
}
