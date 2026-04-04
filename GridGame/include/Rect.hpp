#pragma once

struct Rect {
    float x, y, w, h;

    float Left()   const { return x; }
    float Right()  const { return x + w; }
    float Top()    const { return y; }
    float Bottom() const { return y + h; }

    bool Contains(float px, float py) const {
        return px >= Left() && px <= Right()
            && py >= Top() && py <= Bottom();
    }
};
