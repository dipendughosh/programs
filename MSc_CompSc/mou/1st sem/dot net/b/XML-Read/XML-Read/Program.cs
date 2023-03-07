using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace XML_Read
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlTextReader reader = new XmlTextReader("Books.Xml");

            while (reader.Read())
            {
                switch (reader.NodeType)
                {
                    case XmlNodeType.Element: // Tha node is an element
                        Console.Write("<" + reader.Name);

                        while (reader.MoveToNextAttribute())
                            Console.Write(" " + reader.Name + "='" + reader.Value + "'");
                        Console.WriteLine(">");

                        break;                        

                        
                    case XmlNodeType.Text: // Display the text in each end element
                        Console.WriteLine(reader.Value);

                        break;
                    case XmlNodeType.EndElement: // Display the end of the element
                        Console.Write("</" + reader.Name);
                        Console.WriteLine(">");

                        break;
                }
            }
            Console.ReadLine();
        }
    }

}

