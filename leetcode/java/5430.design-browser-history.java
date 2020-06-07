import java.util.LinkedList;

class BrowserHistory {
    String currUrl;
    LinkedList<String> backStack = new LinkedList<>();
    LinkedList<String> forwardStack = new LinkedList<>();

    public BrowserHistory(String homepage) {
        currUrl = homepage;
    }

    public void visit(String url) {
        backStack.push(currUrl);
        currUrl = url;
        forwardStack.clear();

    }

    public String back(int steps) {
        if (backStack.isEmpty()) {
            return currUrl;
        }

        for (int i = 0; i < steps; i++) {
            if (backStack.isEmpty())
                break;
            forwardStack.push(currUrl);
            currUrl = backStack.pop();
        }

        return currUrl;
    }

    public String forward(int steps) {
        if (forwardStack.isEmpty()) {
            return currUrl;
        }
        for (int i = 0; i < steps; i++) {
            if (forwardStack.isEmpty())
                break;

            backStack.push(currUrl);
            currUrl = forwardStack.pop();
        }

        return currUrl;
    }
}
