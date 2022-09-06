using System.Text;

class Test
{
    struct Tree
    {
        public int left;
        public int right;
    }

    static Tree[] tree;
    static int max;
    static StringBuilder sb;

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        sb = new StringBuilder();

        int n = Convert.ToInt32(sr.ReadLine());

        tree = new Tree[n];
        max = n;

        for (int i = 0; i < n; ++i)
        {
            char[] input = Array.ConvertAll(sr.ReadLine().Split(), char.Parse);

            if (input[1] != '.')
                tree[input[0] - 'A'].left = input[1] - 'A';

            if (input[2] != '.')
                tree[input[0] - 'A'].right = input[2] - 'A';
        }

        Preorder(0);
        sb.AppendLine();
        Inorder(0);
        sb.AppendLine();
        Postorder(0);

        sw.Write(sb.ToString());
        sw.Close();
    }

    static void Preorder(int cur)
    {
        sb.Append((char)(cur + 'A'));

        if (tree[cur].left != 0)
            Preorder(tree[cur].left);

        if (tree[cur].right != 0)
            Preorder(tree[cur].right);
    }

    static void Inorder(int cur)
    {
        if (tree[cur].left != 0)
            Inorder(tree[cur].left);

        sb.Append((char)(cur + 'A'));

        if (tree[cur].right != 0)
            Inorder(tree[cur].right);
    }

    static void Postorder(int cur)
    {
        if (tree[cur].left != 0)
            Postorder(tree[cur].left);

        if (tree[cur].right != 0)
            Postorder(tree[cur].right);

        sb.Append((char)(cur + 'A'));
    }
}