namespace Lists.SimpleLinkedList
{
    class SimpleLinkedList<T>
    {
        private SimpleLinkedListNode<T> head;

        public SimpleLinkedList()
        {
            head = null;
        }

        public void AddElement(T element)
        {
            var node = new SimpleLinkedListNode<T>(element);

            if (head == null)
            {
                head = node;
            }
            else
            {
                var temp = head;

                while (temp.Next != null)
                {
                    temp = temp.Next;
                }

                temp.Next = node;
            }
        }

        public T GetElement(int id)
        {
            var i = 0;
            var temp = head;

            if (temp == null)
            {
                return default(T);
            }

            do
            {
                if (i == id)
                {
                    break;
                }

                i++;
                temp = temp.Next;

            } while (temp.Next != null);

            return temp.Element;
        }

        public bool RemoveElement(int id)
        {
            var i = 1;
            var temp = head;

            if (temp == null)
            {
                return false;
            }

            if (id == 0)
            {
                if (head.Next != null)
                {
                    head = head.Next;
                }
                else
                {
                    head = null;
                }
            }
            else
            {
                while (temp.Next != null)
                {
                    var previous = temp;
                    temp = temp.Next;

                    if (id == i)
                    {
                        previous.Next = temp.Next;
                        return true;
                    }

                    i++;
                }
            }
            
            return false;
        }
    }
}
