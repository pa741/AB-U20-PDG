#include "Medico.h"
#include "Paciente.h"
#include "Cita.h"
class FakeData
{
public:
    FakeData(IDataProvider *proveedor)
    {
        ProveedorDatos = proveedor;
    }
    void GenerateData(int medics, int patients)
    {
        vector<Medico> medicos;
        vector<Paciente> pacientes;
        for (int i = 0; i < medics; i++)
        {
            Medico med = CreateMedico();
            medicos.push_back(med);
            med.Save();
        }
        for (int i = 0; i < patients; i++)
        {
            Paciente pac = CreatePaciente();
            pacientes.push_back(pac);
            pac.Save();
        }
        int citas = min(medics, patients);
        for (int i = 0; i < citas; i++)
        {
            Cita cita = CreateCita(pacientes[i], medicos[i]);
            cita.Save();
        }
    }
    IDataProvider *ProveedorDatos;
    string GenerateDni()
    {
        string dni = "";
        for (int i = 0; i < 8; i++)
        {
            dni += to_string(rand() % 10);
        }
        string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
        int resto = stoi(dni) % 23;
        dni += letras[resto];
        return dni;
    }
    string RandomName()
    {
        string names[] = {"Juan", "Pedro", "Maria", "Jose", "Luis", "Ana", "Laura", "Carlos", "Sara", "Pablo", "Raul", "Sergio", "Javier", "Rosa", "Carmen", "Antonio", "Manuel", "Ramon", "Jorge", "Alvaro", "David", "Daniel", "Miguel", "Ruben", "Alberto", "Diego", "Fernando", "Francisco", "Joaquin", "Javier", "Rafael", "Ricardo", "Roberto", "Victor", "Vicente", "Xavier", "Yago", "Zacarias"};
        return names[rand() % names->length()];
    }
    string RandomSurname()
    {
        string surnames[] = {"Garcia", "Fernandez", "Lopez", "Martinez", "Sanchez", "Perez", "Gonzalez", "Rodriguez", "Ramirez", "Saez", "Gomez", "Vazquez", "Torres", "Jimenez", "Diaz", "Alvarez", "Ruiz", "Navarro", "Marin", "Hernandez", "Sanz", "Iglesias", "Ortega", "Castro", "Rubio", "Molina", "Delgado", "Ortiz", "Suarez", "Morales", "Garrido", "Santos", "Blanco", "Castillo", "Lorenzo"};
        return surnames[rand() % surnames->length()];
    }
    string RandomSpeciality()
    {
        string specialities[] = {"Cardiologia", "Dermatologia", "Endocrinologia", "Gastroenterologia", "Geriatría", "Hematologia", "Infectologia", "Medicina interna", "Nefrologia", "Neumologia", "Neurologia", "Oncologia", "Pediatría", "Psiquiatria", "Reumatologia", "Traumatologia", "Urologia"};
        return specialities[rand() % specialities->length()];
    }
    string RandomSickness()
    {
        string sicknesses[] = {"Gripe", "Resfriado", "Bronquitis", "Neumonia", "Tos", "Dolor de cabeza", "Dolor de estomago", "Dolor de garganta", "Dolor de espalda", "Dolor de muelas"};
        return sicknesses[rand() % sicknesses->length()];
    }
    Medico CreateMedico()
    {
        string dni = GenerateDni();
        string nombre = RandomName();
        string apellido = RandomSurname();
        string especialidad = RandomSpeciality();
        return Medico(nombre + " " + apellido, dni, ProveedorDatos, especialidad);
    }
    Paciente CreatePaciente()
    {
        string dni = GenerateDni();
        string nombre = RandomName();
        string apellido = RandomSurname();
        list<string> enfermedades;
        enfermedades.push_back(RandomSickness());
        return Paciente(nombre + " " + apellido, dni, ProveedorDatos, enfermedades);
    }
    Cita CreateCita(Paciente paciente, Medico med)
    {
        return Cita(med, paciente, ProveedorDatos);
    }
};