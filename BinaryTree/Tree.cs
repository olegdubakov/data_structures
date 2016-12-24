using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    class Tree
    {
        private Node root;

        public void Add(int value)
        {
            if (root == null)
            {
                root = new Node()
                {
                    Value = value
                };
            }
            else
            {
               AddTo(root, value); 
            }
        }
        
        public void PrintTree()
        {
            RecursionWalk(root, (n) =>
            {
                Console.WriteLine(n + " ");
            });
        }

        private void RecursionWalk(Node node, Action<object> command)
        {
            if (node.Left != null)
            {
                RecursionWalk(node.Left, command);
            }

            command.Invoke(node.Value);

            if (node.Right != null)
            {
                RecursionWalk(node.Right, command);
            }
        }
        
        private void AddTo(Node node, int value)
        {
            if (value > node.Value)
            {
                if (node.Right == null)
                {
                    node.Right = new Node()
                    {
                        Value = value
                    };
                }
                else
                {
                    AddTo(node.Right, value);
                }
            }
            else if(value < node.Value)
            {
                if (node.Left == null)
                {
                    node.Left = new Node()
                    {
                        Value = value
                    };
                }
                else
                {
                    AddTo(node.Left, value);
                }
            }
        }
    }
}
