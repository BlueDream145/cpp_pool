/*
** EPITECH PROJECT, 2019
** Engine.hpp
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
	#define ENGINE_HPP_

    #include <string>

    class Engine {
        public:
            Engine();
            virtual ~Engine();
            Engine& operator=(Engine const &);
            
            std::string	obtainCPUModel() const;
            int obtainCoreNb() const;
            float *obtainCorePercent() const;
            float *obtainRam() const;
            float *obtainSwap() const;
            int	obtainNbTasks() const;
            float *obtainLoadAvg() const;

            void defineCPUModel(std::string);
            void defineCoreNb(int core);
            void defineCorePercent(float*);
            void defineRam(float*);
            void defineSwap(float*);
            void defineNbTasks(int);
            void defineLoadAvg(float*);
        private:
            std::string	_CPUModel;
            int _coreNb;
            float *_corePercent;
            float *_ram;
            float *_swap;
            int _nbTasks;
            float *_loadAvg;
    };

#endif /* !ENGINE_HPP_ */