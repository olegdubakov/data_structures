using System;

namespace Lists.DoublyLinkedList
{
    class DoublyLinkedList<T>
    {
        private DoublyLinkedListNode<T> head;
        private DoublyLinkedListNode<T> tail;

        public DoublyLinkedList()
        {
            head = tail = null;
        }

        public void AddToEnd(T element)
        {
            var node = new DoublyLinkedListNode<T>(element);

            if (head == null)
            {
                head = tail = node;
            }
            else
            {
                tail.Next = node;
                tail = tail.Next;
            }
        }
        public void AddToBegin(T value)
        {
            var newElement = new DoublyLinkedListNode<T>(value);
            newElement.Next = head;
            head = newElement;
        }

        public T GetElement(int id)
        {
            var i = 0;
            var temp = head;

            if (temp == null)
            {
                throw new NullReferenceException();
            }

            while (temp != null)
            {
                if (i == id)
                {
                    return temp.Element;
                }
                
                i++;
                temp = temp.Next;
            }

            throw new IndexOutOfRangeException();
        }

        public int Count
        {
            get
            {
                int i = 0;
                var temp = head;
                
                while (temp != null)
                {
                    i++;
                    temp = temp.Next;
                }

                return i;
            }
        }
    }
}
