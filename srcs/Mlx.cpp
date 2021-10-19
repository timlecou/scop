#include "scop.h"

Mlx::Mlx(void)
{
}

Mlx::Mlx(const Mlx &mlx)
{
    this->ptr = mlx.ptr;
    this->win_ptr = mlx.win_ptr;
}

Mlx::~Mlx(void)
{
}

Mlx &Mlx::operator= (const Mlx &mlx)
{
    this->ptr = mlx.ptr;
    this->win_ptr = mlx.win_ptr;
    return (*this);
}

void    Mlx::init(void)
{
    void	*ptr = mlx_init();
	setPtr(ptr);
}

void    *Mlx::getPtr(void) const
{
    return (this->ptr);
}

void    Mlx::setPtr(void *ptr)
{
    this->ptr = ptr;
}

void    *Mlx::getWinPtr(void) const
{
    return (this->win_ptr);
}

void    Mlx::setWinPtr(void *win_ptr)
{
    this->win_ptr = win_ptr;
}

void    *Mlx::getImg(void) const
{
    return (this->img);
}

void    Mlx::setImg(void *img)
{
    this->img = img;
}
