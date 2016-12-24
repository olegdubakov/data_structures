using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lists.DoublyLinkedList;
using Lists.SimpleLinkedList;

namespace Lists
{
    class Program
    {
        static void Main(string[] args)
        {
            // Simple linked list
            var slist = new SimpleLinkedList<int>();

            slist.AddElement(2);
            slist.AddElement(4);
            slist.AddElement(3);
            slist.AddElement(7);

            Console.WriteLine("list[2]: " + slist.GetElement(2));

            slist.RemoveElement(2);

            Console.WriteLine("list[2]: " + slist.GetElement(2));

            Console.WriteLine();
            // Doubly linked list
            var doublyLinkedList = new DoublyLinkedList<string>();

            doublyLinkedList.AddToEnd("one");
            doublyLinkedList.AddToEnd("two");
            doublyLinkedList.AddToEnd("oleg");
            doublyLinkedList.AddToEnd("test");
            doublyLinkedList.AddToBegin("begin");

            for (var i = 0; i < doublyLinkedList.Count; i++)
            {
                Console.WriteLine(doublyLinkedList.GetElement(i));
            }
        }
    }
}
