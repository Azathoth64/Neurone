#ifndef A56F0022_3C3C_4960_A9AD_845CED82763A
#define A56F0022_3C3C_4960_A9AD_845CED82763A

namespace Neurone::Components
{
    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual const std::string& name(); // returns 'IComponent'
    };
}

#endif /* A56F0022_3C3C_4960_A9AD_845CED82763A */
