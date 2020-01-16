/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** Class file
*/

namespace Component {
protected:
    class Component_input{
        int input_port[];
        int input_value[];
    };
    class Component_output{
        int output_port[];
        int output_value[];
    };
    class Component_extra {
        int strobe_port;
        int clock_port;
        int inithib_port;
        bool strobe;
        bool clock;
        bool inithib;
    }
public:
    int *set_input(int *) const;
}

class simple_chipset : public Component{
    
}