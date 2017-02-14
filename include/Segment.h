#ifndef SEGMENT_H
#define SEGMENT_H

class Segment {
    private:
        float pos[2];
        float cel[2];
        float norm[2];
        float tang[2];
        float size;
    public:
        Segment(const float _pos[2], const float _cel[2], const float _norm[2], float _size): size(_size)
        {
            for (int i = 0 ; i < 2 ; i++)
            {
                pos[i] = _pos[i];
                cel[i] = _cel[i];
                norm[i] = _norm[i];
            }
			// Here in '2d' : [normx,normy,0] vect [0,0,-1];
			tang[0] = norm[1]; tang[1] = -norm[0];
        }

        inline float* getPos(void) {
            return pos;
        }
        inline float getX(void) const {
            return pos[0];
        }
        inline float getY(void) const {
            return pos[1];
        }
        inline float* getCel(void) {
            return cel;
        }
        inline float getCelX(void) const {
            return cel[0];
        }
        inline float getCelY(void) const {
            return cel[1];
        }
        inline float* getNorm(void) {
            return norm;
        }
        inline float getNormX(void) const {
            return norm[0];
        }
        inline float getNormY(void) const {
            return norm[1];
        }
        inline float* getTang(void) {
            return tang;
        }
        inline float getTangX(void) const {
            return tang[0];
        }
        inline float getTangY(void) const {
            return tang[1];
        }
        inline float getSize(void) const {
            return size;
        }
};

#endif