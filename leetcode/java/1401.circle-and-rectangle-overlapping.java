import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // 左下角 && 右上角
        if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2)
            return true;
        int dis = (x1 - x_center) * (x1 - x_center) + (y1 - y_center) * (y1 - y_center);

        if (radius * radius >= dis) {
            return true;
        }
        var arr = getYDecIndex(radius, x_center, y_center, x1);
        for (var i : arr) {
            if (valid(y1, y2, i))
                return true;
        }

        arr = getYDecIndex(radius, x_center, y_center, x2);
        for (var i : arr) {
            if (valid(y1, y2, i))
                return true;
        }

        arr = getXDecIndex(radius, x_center, y_center, y1);
        for (var i : arr) {
            if (valid(x1, x2, i))
                return true;
        }

        arr = getXDecIndex(radius, x_center, y_center, y2);
        for (var i : arr) {
            if (valid(x1, x2, i))
                return true;
        }
        return false;
    }

    private boolean valid(int l, int r, double x) {
        return l <= x && r >= x;
    }

    private List<Double> getYDecIndex(int radius, int x_center, int y_center, int x1) {
        double part = Math.sqrt(radius * radius - (x1 - x_center) * (x1 - x_center));
        List<Double> r = new ArrayList<>();

        r.add(-part + y_center);
        r.add(part + y_center);
        return r;

    }

    private List<Double> getXDecIndex(int radius, int x_center, int y_center, int y1) {

        double part = Math.sqrt(radius * radius - (y1 - y_center) * (y1 - y_center));
        List<Double> r = new ArrayList<>();

        r.add(-part + x_center);
        r.add(part + x_center);
        return r;
    }
}
