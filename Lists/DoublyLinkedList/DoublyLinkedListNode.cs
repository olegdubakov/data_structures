namespace Lists.DoublyLinkedList
{
    class DoublyLinkedListNode<T>
    {
        public T Element
        {
            get;
            set;
        }

        public DoublyLinkedListNode<T> Next
        {
            get;
            set;
        }
        public DoublyLinkedListNode<T> Prev
        {
            get;
            set;
        }

        public DoublyLinkedListNode(T element)
        {
            this.Element = element;
            this.Next = null;
            this.Prev = null;
        }
    }
}
