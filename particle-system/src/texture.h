#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include <QImage>
#include <QGLWidget>

using namespace std;

class Texture
{
private:
    QImage image;
    GLenum format;
    GLenum type;
    GLenum internalFormat;
    GLuint textureIndex;
    GLuint textureId;
    unsigned int height;
    unsigned int width;

    void loadImage(const string& path);
    GLuint unitFromIndex(GLuint index);
public:
    Texture(const string& imagePath, GLuint textureIndex = 0);
    ~Texture();

    GLuint bind();
    void unBind();
    void init();
    void disposeGL();
    GLuint getTextureId() const;
    GLuint getTextureIndex() const;

    void resize(int width, int height);
    void setTextureIndex(GLuint index);
    void setFiltering(GLint filtering);

};

#endif // TEXTURE_H
