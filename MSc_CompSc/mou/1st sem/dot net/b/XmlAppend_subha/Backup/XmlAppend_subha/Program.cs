using System;
using System.Collections.Generic;
//using System.Text;
using System.Xml;

namespace XmlAppend_subha
{
    class Program
    {
        static void Main(string[] args)
        {
            

            XmlNode nodeTitle;
            XmlNode nodePrice;
            XmlDocument doc = new XmlDocument();
            doc.LoadXml("<book genre='novel' ISBN='1-861001-57-5'>" +
                        "<title>A Beautiful Mind</title>" + "<price>98.50</price>" +
                        "</book>");

            Console.WriteLine("\nDisplay the Initial XML...");
            Console.WriteLine("\n");
            doc.Save(Console.Out);
            //doc.Save("C:\\initial.Xml");

            XmlNode root = doc.DocumentElement;
            //XmlNode node = root.DocumentElement;

            //Create a new node.
            XmlElement elem = doc.CreateElement("price");
            elem.InnerText = "19.95";
            //Add the node to the document.
            root.AppendChild(elem);

            Console.WriteLine("\n\nDisplay the modified XML After Appending the new price...");
            Console.WriteLine("\n");
            doc.Save(Console.Out);
            //doc.Save("C:\\first-modification.Xml");
    

            nodeTitle = doc.SelectSingleNode("//book");
            string x = nodeTitle.InnerText;
            Console.WriteLine("\n\nThe selected node is:" + x);
            doc.Save(Console.Out);
            //doc.Save("C:\\select.Xml");

            //Remove the title element.
            root.RemoveChild(root.FirstChild);//node.FirstChild);
            Console.WriteLine("\n\nAfter Deleting the Selected XML...");
            Console.WriteLine("\n");
            doc.Save(Console.Out);
            //doc.Save("C:\\after-deletion.Xml");

            nodePrice = doc.SelectSingleNode("/book[price > 90.00]");
            string y = nodePrice.InnerText;
            Console.WriteLine("\n\nThe Selected Price is: " + y );
            doc.Save(Console.Out);
            //doc.Save("C:\\select1.Xml");
    

            //Update the child
            XmlElement ttl = doc.CreateElement("price");
            ttl.InnerText = "80.00";

            //Replace the title element.
            root.ReplaceChild(ttl, root.FirstChild);

            Console.WriteLine("\n\nPrice After modification of the XML...");
            Console.WriteLine("\n");
            doc.Save(Console.Out);
            //doc.Save("C:\\final.Xml");

            Console.ReadLine();

        }
    }
}
