struct Renderer
{
  virtual string render_as() const = 0;
};

struct Shape
{
  string name;
  const Renderer& renderer;

  Shape(const Renderer& renderer): renderer{renderer} {
  }

  string str() const
  {
    ostringstream oss;
    oss << "Drawing " << name << " as "
      << renderer.render_as();
    return oss.str();
  }
};

struct Triangle : Shape
{
  explicit Triangle(const Renderer& renderer)
    : Shape{renderer}
  {
    name = "Triangle";
  }
};

struct Square : Shape
{
  explicit Square(const Renderer& renderer)
    : Shape{renderer}
  {
    name = "Square";
  }
};

struct RasterRenderer : Renderer
{
  string render_as() const override
  {
    return "pixels";
  }
};

struct VectorRenderer : Renderer
{
  string render_as() const override
  {
    return "lines";
  }
};
