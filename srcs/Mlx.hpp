#ifndef MLX_HPP
# define MLX_HPP

class Mlx
{
    private:
        void    *ptr;
        void    *win_ptr;
        void    *img;
    public:
        Mlx(void)
        {
        }
        Mlx(const Mlx &mlx)
        {
            this->ptr = mlx.ptr;
            this->win_ptr = mlx.win_ptr;
        }
        ~Mlx(void)
        {
        }
        Mlx &operator= (const Mlx &mlx)
        {
            this->ptr = mlx.ptr;
            this->win_ptr = mlx.win_ptr;
            return (*this);
        }

        void    *getPtr(void) const
        {
            return (this->ptr);
        }

        void    setPtr(void *ptr)
        {
            this->ptr = ptr;
        }

        void    *getWinPtr(void) const
        {
            return (this->win_ptr);
        }

        void    setWinPtr(void *win_ptr)
        {
            this->win_ptr = win_ptr;
        }

        void    *getImg(void) const
        {
            return (this->img);
        }

        void    setImg(void *img)
        {
            this->img = img;
        }

};

#endif