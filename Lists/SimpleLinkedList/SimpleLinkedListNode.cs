namespace Lists.SimpleLinkedList
{
    class SimpleLinkedListNode<T>
    {
        public T Element
        {
            get;
            set;
        }

        public SimpleLinkedListNode<T> Next
        {
            get;
            set;
        }

        public SimpleLinkedListNode(T element)
        {
            this.Element = element;
            this.Next = null;
        }
    }
}
