class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        return (C - A) * (D - B) + (G - E) * (H - F) - max(0, min(C, G) - max(A, E)) * max(0, min(D, H) - max(B, F))
        