import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class longestCommonSubsequenceSolutionTest {

    @Test
    void longestCommonSubsequence() {
        var o = new longestCommonSubsequenceSolution();
        assertEquals(o.longestCommonSubsequence("ace", "abcde"), 3);
        assertEquals(o.longestCommonSubsequence("abcde", "ace"), 3);
        assertEquals(o.longestCommonSubsequence("abcde", ""), 0);
        assertEquals(o.longestCommonSubsequence("", "ace"), 0);
    }
}