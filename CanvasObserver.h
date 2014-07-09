#ifndef CANVASOBSERVER_H
#define CANVASOBSERVER_H

class CanvasObserver
{
public:
    virtual ~CanvasObserver();
    virtual void drawSameShapeType() = 0;
};

#endif // CANVASOBSERVER_H
