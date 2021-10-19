#ifndef MLX_HPP
# define MLX_HPP

class Mlx
{
    private:
        void    *ptr;
        void    *win_ptr;
        void    *img;
    public:
        Mlx(void);
        Mlx(const Mlx &mlx);
        ~Mlx(void);
        Mlx &operator= (const Mlx &mlx);

        //getters and setters
        void    *getPtr(void) const;
        void    setPtr(void *ptr);
        void    *getWinPtr(void) const;
        void    setWinPtr(void *win_ptr);
        void    *getImg(void) const;
        void    setImg(void *img);

        void    init(void);

};

#endif