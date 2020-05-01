public class Solution
{
    public int[] FindDiagonalOrder(int[][] matrix)
    {
        if (matrix.Length == 0 || matrix[0].Length == 0) return Array.Empty<int>();
        List<List<int>> m = new List<List<int>>();
        for (int i = 0; i < matrix.Length; i++)
        {
            for (int j = 0; j < matrix[i].Length; j++)
            {
                if (i + j >= m.Count)
                {
                    m.Add(new List<int>());
                }

                m[i + j].Add(matrix[i][j]);
            }
        }

        int[] res = new int[matrix.Length * matrix[0].Length];

        int idx = 0;
        bool even = true;
        foreach (var item in m)
        {
            if (even)
            {
                item.Reverse();
            }

            foreach (int v in item)
            {
                res[idx++] = v;
            }

            even = !even;
        }

        return res;
    }
}