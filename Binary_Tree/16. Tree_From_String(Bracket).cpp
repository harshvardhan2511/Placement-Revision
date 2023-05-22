/*
TC = O(N)
SC = O(N)
Link = https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1
*/
class Solution
{
public:
    /* Helper function that allocates a new node */
    Node *newNode(int data)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = data;
        node->left = node->right = NULL;
        return (node);
    }

    // function to return the index of close parenthesis
    int findIndex(string str, int si, int ei)
    {
        if (si > ei)
            return -1;

        // Inbuilt stack
        stack<char> s;

        for (int i = si; i <= ei; i++)
        {

            // if open parenthesis, push it
            if (str[i] == '(')
                s.push(str[i]);

            // if close parenthesis
            else if (str[i] == ')')
            {
                if (s.top() == '(')
                {
                    s.pop();

                    // if stack is empty, this is
                    // the required index
                    if (s.empty())
                        return i;
                }
            }
        }
        // if not found return -1
        return -1;
    }

    // function to construct tree from string
    Node *treeBuild(string str, int si, int ei)
    {
        // Base case
        if (si > ei)
            return NULL;

        int num = 0;
        // In case the number is having more than 1 digit
        while (si <= ei && str[si] >= '0' && str[si] <= '9')
        {
            num *= 10;
            num += (str[si] - '0');
            si++;
        }

        // new root
        Node *root = newNode(num);
        int index = -1;

        // if next char is '(' find the index of
        // its complement ')'
        if (si <= ei && str[si] == '(')
            index = findIndex(str, si, ei);

        // if index found
        if (index != -1)
        {

            // call for left subtree
            root->left = treeBuild(str, si + 1, index - 1);

            // call for right subtree
            root->right = treeBuild(str, index + 2, ei - 1);
        }
        return root;
    }
    // function to construct tree from string
    Node *treeFromString(string str)
    {

        return treeBuild(str, 0, str.size() - 1);
    }
};