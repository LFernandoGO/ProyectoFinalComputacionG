#include <iostream>
#include <cmath>

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include "stb_image.h"

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Load Models
#include "SOIL2/SOIL2.h"


// Other includes
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Texture.h"
#include "modelAnim.h"

// Function prototypes
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
void MouseCallback(GLFWwindow *window, double xPos, double yPos);
void DoMovement();
void animacion();

// Window dimensions
const GLuint WIDTH = 1080, HEIGHT = 720;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Camera
Camera  camera(glm::vec3(-100.0f, 4.5f, -25.0f));
GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;
bool keys[1024];
bool firstMouse = true;
float range = 0.0f;
float rot = 0.0f;
// Incrementos de las animaciones simples
float rot2 = 0.0f;
float rotVen = 0.0f;
float rotVenIzq = 0.0f;
float rotVenDer = 0.0f;
float rotSilla = 0.0f;
float rotPuerta = 0.0f;
float movCamera = 0.0f;
// Variables de animaciones Simples
bool anima = false;
bool anima2 = false;
bool animaVen1 = false;
bool animaVen2 = false;
bool animaVenIzq1 = false;
bool animaVenIzq2 = false;
bool animaVenDer1 = false;
bool animaVenDer2 = false;
bool animaPuerta1 = false;
bool animaPuerta2 = false;
bool animaSilla1 = false;
bool animaSilla2 = false;

// Variables animaciones complejas

//COCHE 1
float movKitX = 0.0;
float movKitZ = 0.0;
float rotKitCoche1 = 0.0;

bool circuito = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;
bool recorrido6 = false;
bool recorrido7 = false;

//COCHE 2
float movKitXCoche2 = 0.0;
float movKitZCoche2 = 0.0;
float rotKitCoche2 = 0.0;

bool circuitoCoche2 = false;
bool recorrido1Coche2 = true;
bool recorrido2Coche2 = false;
bool recorrido3Coche2 = false;
bool recorrido4Coche2 = false;
bool recorrido5Coche2 = false;
bool recorrido6Coche2 = false;
bool recorrido7Coche2 = false;

//COCHE 3
float movKitXCoche3 = 0.0;
float movKitZCoche3 = 0.0;
float rotKitCoche3 = 0.0;

bool circuitoCoche3 = false;
bool recorrido1Coche3 = true;
bool recorrido2Coche3 = false;
bool recorrido3Coche3 = false;
bool recorrido4Coche3 = false;
bool recorrido5Coche3 = false;
bool recorrido6Coche3 = false;
bool recorrido7Coche3 = false;

//COCHE 4
float movKitXCoche4 = 0.0;
float movKitZCoche4 = 0.0;
float rotKitCoche4 = 0.0;

bool circuitoCoche4 = false;
bool recorrido1Coche4 = true;
bool recorrido2Coche4 = false;
bool recorrido3Coche4 = false;
bool recorrido4Coche4 = false;
bool recorrido5Coche4 = false;
bool recorrido6Coche4 = false;
bool recorrido7Coche4 = false;

//PTERODACTILO
float movKitXPtero = 0.0;
float movKitZPtero = 0.0;
float rotKitPtero = 0.0;
float rotPtero = 0.0;

bool circuitoPtero = false;
bool animPtero1 = false;
bool animPtero2 = true;
bool animPtero3 = false;
bool recorrePtero1 = true;
bool recorrePtero2 = false;
bool recorrePtero3 = false;
bool recorrePtero4 = false;
bool recorrePtero5 = false;
bool recorrePtero6 = false;
bool recorrePtero7 = false;
bool recorrePtero8 = false;

//T-REX
float movKitXT;
float movKitZT;
float rotKitT;
float rotT;
float rotTM;

bool circuitoTRex = false;
bool animTRex1 = false;
bool animTRex2 = true;
bool animTRex3 = false;
bool animTRex4 = false;
bool animTRex5 = false;
bool recorreTRex1 = true;
bool recorreTRex2 = false;
bool recorreTRex3 = false;

//VELOCIRAPTOR
float movKitXV;
float movKitZV;
float rotKitV;

bool circuitoVel = false;
bool recorreVel1 = true;
bool recorreVel2 = false;
bool recorreVel3 = false;

//MOSASSAURO
float movKitXMosa = 0.0;
float movKitZMosa = 0.0;
float rotKitMosa = 0.0;
float rotMosa = 0.0;
float traMosa = 0.0;

bool circuitoMosa = false;
bool animMosa1 = false;
bool animMosa2 = true;
bool animMosa3 = false;
bool animMosa4 = true;
bool animMosa5 = false;
bool recorreMosa1 = true;
bool recorreMosa2 = false;
bool recorreMosa3 = false;
bool recorreMosa4 = false;
bool recorreMosa5 = false;
bool recorreMosa6 = false;
bool recorreMosa7 = false;
bool recorreMosa8 = false;

//CUELLO LARGO
bool animaCuello1 = true;
bool animaCuello2 = true;
bool animaCuello3 = false;
bool animaCuello4 = true;
bool animaCuello5 = false;
float rotLargoCuello = 0.0f;
float rotLargoCola = 0.0f;

//CUELLO LARGO2
bool anima2Cuello1 = true;
bool anima2Cuello2 = true;
bool anima2Cuello3 = false;
bool anima2Cuello4 = true;
bool anima2Cuello5 = false;
float rotLargoCuello2 = 0.0f;
float rotLargoCola2 = 0.0f;

//MANOS PERSONAS GRADAS
bool animaMano1 = true;
bool animaMano2 = true;
bool animaMano3 = false;
float rotMano = 0.0f;

//PERSONAS CASAS
bool anima3Lego1 = true;
bool anima3Lego2 = true;
bool anima3Lego3 = false;
bool anima3Lego4 = true;
bool anima3Lego5 = false;
float rot3LegoM = 0.0f;
float rot3LegoC = 0.0f;

//AGUA
float tiempo;


// Light attributes
glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
glm::vec3 PosIni(-95.0f, 1.0f, -45.0f);
glm::vec3 lightDirection(0.0f, -1.0f, -1.0f);

bool active;


// Deltatime
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame

// Keyframes
float posX =PosIni.x, posY = PosIni.y, posZ = PosIni.z, rotRodIzq = 0;

#define MAX_FRAMES 9
int i_max_steps = 190;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;

// Positions of the point lights
glm::vec3 pointLightPositions[] = {
	glm::vec3(posX,posY,posZ),
	glm::vec3(0,0,0),
	glm::vec3(0,0,0),
	glm::vec3(0,0,0)
};

glm::vec3 LightP1;


int main()
{
	// Init GLFW
	glfwInit();

	// Set all the required options for GLFW
	/*(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Proyecto Final", nullptr, nullptr);

	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

	// Set the required callback functions
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetCursorPosCallback(window, MouseCallback);
	printf("%f", glfwGetTime());

	// GLFW Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Define the viewport dimensions
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	// OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// Carga de Shaders

	Shader lightingShader("Shaders/lighting.vs", "Shaders/lighting.frag");
	Shader lampShader("Shaders/lamp.vs", "Shaders/lamp.frag");
	Shader lampShader2("Shaders/lamp2.vs", "Shaders/lamp2.frag");
	Shader SkyBoxshader("Shaders/SkyBox.vs", "Shaders/SkyBox.frag");
	Shader animShader("Shaders/anim.vs", "Shaders/anim.frag");
	Shader Anim2("Shaders/anim2.vs", "Shaders/anim2.frag");

	// Carga modelo PISOS
	Model Piso((char*)"Models/Construcciones/PisoArboles.obj");
	Model Agua((char*)"Models/Construcciones/Agua.obj");
	Model Camino1((char*)"Models/Construcciones/Camino1.obj");
	Model Camino2((char*)"Models/Construcciones/Camino2.obj");

	// Carga de modelos CONSTRUCCIONES
	Model Domo((char*)"Models/Construcciones/Domo.obj");
	Model Lab((char*)"Models/Construcciones/Lab.obj");
	Model Grada((char*)"Models/Construcciones/Grada.obj");
	Model Arbol((char*)"Models/Construcciones/Arbol.obj");
	Model Villas((char*)"Models/Villas/Villas.obj");
	//Model Rejas((char*)"Models/Construcciones/Rejas.obj");
	Model PuertaDer((char*)"Models/Construcciones/PuertaDer.obj");
	Model PuertaIzq((char*)"Models/Construcciones/PuertaIzq.obj");
	Model PuertaDer2((char*)"Models/Construcciones/PuertaDer2.obj");
	Model PuertaIzq2((char*)"Models/Construcciones/PuertaIzq2.obj");

	// Carga de modelos ANIMACIONES COMPLEJAS
	Model Coche((char*)"Models/Construcciones/Coche.obj");
	Model AlaDer((char*)"Models/Dinosaurios/Ptero/AlaDer.obj");
	Model AlaIzq((char*)"Models/Dinosaurios/Ptero/AlaIzq.obj");
	Model PteroCuerpo((char*)"Models/Dinosaurios/Ptero/PteroCuerpo.obj");
	Model Cabeza((char*)"Models/Dinosaurios/Ptero/Cabeza.obj");
	Model MosaCuerpo((char*)"Models/Dinosaurios/Mosa/Mosa.obj");
	Model MosaCola((char*)"Models/Dinosaurios/Mosa/ColaM.obj");

	Model BraDerT((char*)"Models/Dinosaurios/T-Rex/BrazoDerecho.obj");
	Model BraIzqT((char*)"Models/Dinosaurios/T-Rex/BrazoIzquierdo.obj");
	Model ColaT((char*)"Models/Dinosaurios/T-Rex/Cola.obj");
	Model CuerpoT((char*)"Models/Dinosaurios/T-Rex/Cuerpo.obj");
	Model MandibulaT((char*)"Models/Dinosaurios/T-Rex/Mandibula.obj");
	Model PatDerT((char*)"Models/Dinosaurios/T-Rex/PataDerecha.obj");
	Model PatIzqT((char*)"Models/Dinosaurios/T-Rex/PataIzquierda.obj");

	Model BraDerV((char*)"Models/Dinosaurios/Velociraptor/BrazoDerecho.obj");
	Model BraIzqV((char*)"Models/Dinosaurios/Velociraptor/BrazoIzquierdo.obj");
	Model ColaV((char*)"Models/Dinosaurios/Velociraptor/Cola.obj");
	Model CuerpoV((char*)"Models/Dinosaurios/Velociraptor/Cuerpo.obj");
	Model MandibulaV((char*)"Models/Dinosaurios/Velociraptor/Mandibula.obj");
	Model PatDerV((char*)"Models/Dinosaurios/Velociraptor/PataDerecha.obj");
	Model PatIzqV((char*)"Models/Dinosaurios/Velociraptor/PataIzquierda.obj");

	// Carga de Modelos ANIMACIONES SIMPLES
	Model LargoCuerpo((char*)"Models/Dinosaurios/Cuello/Cuerpo.obj");
	Model LargoCola((char*)"Models/Dinosaurios/Cuello/Cola.obj");
	Model LargoCuello((char*)"Models/Dinosaurios/Cuello/Cuello.obj");
	Model LargoCuerpo2((char*)"Models/Dinosaurios/Cuello2/Cuerpo2.obj");
	Model LargoCola2((char*)"Models/Dinosaurios/Cuello2/Cola2.obj");
	Model LargoCuello2((char*)"Models/Dinosaurios/Cuello2/Cuello2.obj");

	// Carga de Modelos de PERSONAS GRADAS
	Model LegoCuerpo((char*)"Models/Personas/Lego4/Cuerpo.obj");
	Model LegoCabeza((char*)"Models/Personas/Lego4/Cabeza.obj");
	Model LegorPie((char*)"Models/Personas/Lego4/rPie.obj");
	Model LegolPie((char*)"Models/Personas/Lego4/lPie.obj");
	Model GradasPies((char*)"Models/Personas/GradasP/Pies.obj");
	Model LegorHand((char*)"Models/Personas/Manos/rHand.obj");
	Model LegolHand((char*)"Models/Personas/Manos/lHand.obj");

	// Carga de Modelos PERSONAS CASAS
	Model Lego3Cuerpo((char*)"Models/Personas/Lego3/Cuerpo.obj");
	Model Lego3Cabeza((char*)"Models/Personas/Lego3/Cabeza.obj");
	Model Lego3rPie((char*)"Models/Personas/Lego3/rPie.obj");
	Model Lego3lPie((char*)"Models/Personas/Lego3/lPie.obj");
	Model Lego3rHand((char*)"Models/Personas/Lego3/rHand.obj");
	Model Lego3lHand((char*)"Models/Personas/Lego3/lHand.obj");
	// Build and compile our shader program

	//Inicialización de KeyFrames
	
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX = 0;
		KeyFrame[i].incX = 0;
		KeyFrame[i].incY = 0;
		KeyFrame[i].incZ = 0;
		KeyFrame[i].rotRodIzq = 0;
		KeyFrame[i].rotInc = 0;
	}



	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] =
	{
		// Positions            // Normals              // Texture Coords
		-0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,
		0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  0.0f,
		0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
		0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,

		-0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,
		0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  1.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,  	1.0f,  1.0f,
		-0.5f,  0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,

		-0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
		-0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
		-0.5f, -0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,

		0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,
		0.5f,  0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  1.0f,
		0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
		0.5f, -0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  0.0f,
		0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,

		-0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,
		0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  1.0f,
		0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
		0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,

		-0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f,
		0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  1.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
		0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f
	};


	GLfloat skyboxVertices[] = {
		// Positions
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};


	GLuint indices[] =
	{  // Note that we start from 0!
		0,1,2,3,
		4,5,6,7,
		8,9,10,11,
		12,13,14,15,
		16,17,18,19,
		20,21,22,23,
		24,25,26,27,
		28,29,30,31,
		32,33,34,35
	};

	// Positions all containers
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};


	// First, set the container's VAO (and VBO)
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	// Normals attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// Texture Coordinate attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);

	// Then, we set the light's VAO (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
	GLuint lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	// We only need to bind to the VBO (to link it with glVertexAttribPointer), no need to fill it; the VBO's data already contains all we need.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Set the vertex attributes (only position data for the lamp))
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)0); // Note that we skip over the other data in our buffer object (we don't need the normals/textures, only positions).
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);


	//SkyBox
	GLuint skyboxVBO, skyboxVAO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1,&skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices),&skyboxVertices,GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);

	// Load textures
	vector<const GLchar*> faces;
	faces.push_back("SkyBox/right.tga");
	faces.push_back("SkyBox/left.tga");
	faces.push_back("SkyBox/top.tga");
	faces.push_back("SkyBox/bottom.tga");
	faces.push_back("SkyBox/back.tga");
	faces.push_back("SkyBox/front.tga");
	
	GLuint cubemapTexture = TextureLoading::LoadCubemap(faces);

	glm::mat4 projection = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);

	// Game loop
	while (!glfwWindowShouldClose(window))
	{

		// Calculate deltatime of current frame
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		DoMovement();
		animacion();


		// Clear the colorbuffer
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Use cooresponding shader when setting uniforms/drawing objects
		lightingShader.Use();
		GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");
		glUniform3f(viewPosLoc, camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
		// Set material properties
		glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 32.0f);
		// == ==========================
		// Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index
		// the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
		// by defining light types as classes and set their values in there, or by using a more efficient uniform approach
		// by using 'Uniform buffer objects', but that is something we discuss in the 'Advanced GLSL' tutorial.
		// == ==========================
		// Directional light
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.ambient"), 0.5f, 0.5f, 0.5f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.diffuse"), 0.4f, 0.4f, 0.4f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "dirLight.specular"), 0.5f, 0.5f, 0.5f);


		// Point light 1
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].diffuse"), LightP1.x, LightP1.y, LightP1.z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[0].specular"), LightP1.x, LightP1.y, LightP1.z);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[0].quadratic"), 0.032f);



		// Point light 2
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].position"), pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].diffuse"), 1.0f, 1.0f, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[1].specular"), 1.0f, 1.0f, 0.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[1].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[1].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[1].quadratic"), 0.032f);

		// Point light 3
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].position"), pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].diffuse"), 0.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[2].specular"), 0.0f, 1.0f, 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[2].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[2].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[2].quadratic"), 0.032f);

		// Point light 4
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[3].position"), pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[3].ambient"), 0.05f, 0.05f, 0.05f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[3].diffuse"), 1.0f, 0.0f, 1.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "pointLights[3].specular"), 1.0f, 0.0f, 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[3].constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[3].linear"), 0.09f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "pointLights[3].quadratic"), 0.032f);

		// SpotLight
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.position"), camera.GetPosition().x, camera.GetPosition().y, camera.GetPosition().z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.direction"), camera.GetFront().x, camera.GetFront().y, camera.GetFront().z);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.ambient"), 0.0f, 0.0f, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.diffuse"), 0.0f, 0.0f, 0.0f);
		glUniform3f(glGetUniformLocation(lightingShader.Program, "spotLight.specular"), 0.0f, 0.0f, 0.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.constant"), 1.0f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.linear"), 0.09f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.quadratic"), 0.032f);
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.cutOff"), glm::cos(glm::radians(12.5f)));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "spotLight.outerCutOff"), glm::cos(glm::radians(15.0f)));

		// Set material properties
		glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 32.0f);

		// Create camera transformations
		glm::mat4 view;
		view = camera.GetViewMatrix();


		// Get the uniform locations
		GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
		GLint projLoc = glGetUniformLocation(lightingShader.Program, "projection");

		// Pass the matrices to the shader
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// Bind diffuse map
		//glBindTexture(GL_TEXTURE_2D, texture1);*/

		// Bind specular map
		/*glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);*/


		glBindVertexArray(VAO);
		glm::mat4 tmp = glm::mat4(1.0f); //Temp



		//MODELOS PARQUE JURASICO 
			
		view = camera.GetViewMatrix();
		glm::mat4 model(1);
		//tmp = model = glm::translate(model, glm::vec3(0, 1, 0));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Domo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Piso.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Grada.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Camino1.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Camino2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lab.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Villas.Draw(lightingShader);

		// Modelos PUERTAS
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(56.56f, 2.5f, 62.064f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(-rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaDer.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(56.56f, 2.5f, 78.829f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaDer.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(56.56f, 2.5f, 94.929f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(-rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaDer.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(56.501f, 2.472f, 65.8f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaIzq.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(56.501f, 2.472f, 82.588f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(-rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaIzq.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(56.501f, 2.472f, 98.685f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaIzq.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(87.111f, 2.514f, 66.170f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaDer2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(87.111f, 2.514f, 83.004f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(-rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaDer2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(87.111f, 2.514f, 99.063f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaDer2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(87.056f, 2.475f, 62.392f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(-rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaIzq2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(87.056f, 2.475f, 79.259f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaIzq2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(87.056f, 2.475f, 95.308f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(-rotPuerta), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PuertaIzq2.Draw(lightingShader);

		// Modelos COCHES
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitX+38.594, 2.376, movKitZ+116.496));
		model = glm::rotate(model, glm::radians(rotKitCoche1), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Coche.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXCoche2 + 78.671, 2.376, movKitZCoche2 + 50.161));
		model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::rotate(model, glm::radians(rotKitCoche2), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Coche.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXCoche3 + 28.427, 2.376, movKitZCoche3 + -85.962));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::rotate(model, glm::radians(rotKitCoche3), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Coche.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXCoche4 + -90.772, 2.376, movKitZCoche4 + -58.910));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::rotate(model, glm::radians(rotKitCoche4), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Coche.Draw(lightingShader);

		// PTERODACTILO
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXPtero-28.482, 31.720, movKitZPtero+34.484));
		model = glm::rotate(model, glm::radians(rotKitPtero), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		PteroCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXPtero -28.467, 31.747, movKitZPtero + 34.461));
		model = glm::rotate(model, glm::radians(rotKitPtero), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Cabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXPtero -28.505, 31.739, movKitZPtero +34.493));
		model = glm::rotate(model, glm::radians(rotKitPtero), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::rotate(model, glm::radians(rotPtero), glm::vec3(0.0f, 0.0f, 1.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		AlaIzq.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXPtero -28.494, 31.739, movKitZPtero +34.496));
		model = glm::rotate(model, glm::radians(rotKitPtero), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::rotate(model, glm::radians(-rotPtero), glm::vec3(0.0f, 0.0f, 1.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		AlaDer.Draw(lightingShader);

		//T-Rex
		//Cola T-Rex
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXT, 0, movKitZT));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-84.0f, 5.4f, -4.4f));
		model = glm::rotate(model, glm::radians(rotT), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ColaT.Draw(lightingShader);

		//Cuerpo T-Rex
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXT, 0, movKitZT));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-83.8f, 8.0f, -8.3420f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoT.Draw(lightingShader);

		//Garra Derecha T-Rex
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXT, 0, movKitZT));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-83.0f, 8.0f, -11.7f));
		model = glm::rotate(model, glm::radians(rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BraDerT.Draw(lightingShader);

		//Garra Izquierda T-Rex
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXT, 0, movKitZT));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-84.8f, 8.0f, -11.6f));
		model = glm::rotate(model, glm::radians(-rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BraIzqT.Draw(lightingShader);

		//Mandibula T-Rex
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXT, 0, movKitZT));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-83.932f, 10.5f, -14.185f));
		model = glm::rotate(model, glm::radians(rotTM), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		MandibulaT.Draw(lightingShader);

		//Pata Derecha T-Rex
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXT, 0, movKitZT));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-82.349f, 7.0f, -8.7f));
		model = glm::rotate(model, glm::radians(rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PatDerT.Draw(lightingShader);

		//Pata Izquierda T-Rex
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXT, 0, movKitZT));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-85.349f, 7.0f, -8.7f));
		model = glm::rotate(model, glm::radians(-rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PatIzqT.Draw(lightingShader);

		//Velociraptor
		//Cola Velociraptor
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXV, 0, movKitZV));
		model = glm::rotate(model, glm::radians(rotKitT), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-84.349f, 5.0f, -6.6f));
		model = glm::rotate(model, glm::radians(rotT), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		ColaV.Draw(lightingShader);

		//Cuerpo Velociraptor
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXV, 0, movKitZV));
		model = glm::rotate(model, glm::radians(rotKitV), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-84.349f, 4.8f, -9.1f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		CuerpoV.Draw(lightingShader);

		//Garra Derecha Velociraptor
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXV, 0, movKitZV));
		model = glm::rotate(model, glm::radians(rotKitV), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-83.7f, 4.3f, -10.5f));
		model = glm::rotate(model, glm::radians(rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BraDerV.Draw(lightingShader);

		//Garra Izquierda Velociraptor
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXV, 0, movKitZV));
		model = glm::rotate(model, glm::radians(rotKitV), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-85.0f, 4.3f, -10.5f));
		model = glm::rotate(model, glm::radians(-rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		BraIzqV.Draw(lightingShader);

		//Mandibula Velociraptor
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXV, 0, movKitZV));
		model = glm::rotate(model, glm::radians(rotKitV), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-84.5f, 6.2f, -11.6f));
		model = glm::rotate(model, glm::radians(rotTM), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		MandibulaV.Draw(lightingShader);

		//Pata Derecha Velociraptor
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXV, 0, movKitZV));
		model = glm::rotate(model, glm::radians(rotKitV), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-83.5f, 4.2f, -8.7f));
		model = glm::rotate(model, glm::radians(rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PatDerV.Draw(lightingShader);

		//Pata Izquierda Velociraptor
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, glm::vec3(movKitXV, 0, movKitZV));
		model = glm::rotate(model, glm::radians(rotKitV), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::translate(model, glm::vec3(-85.2f, 4.2f, -8.7f));
		model = glm::rotate(model, glm::radians(-rotT), glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		PatIzqV.Draw(lightingShader);

		// MOSSASAURO
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXMosa + 7.0 , traMosa, movKitZMosa - 53.312));
		model = glm::rotate(model, glm::radians(rotKitMosa), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		MosaCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(model, PosIni + glm::vec3(movKitXMosa + 7.0, traMosa, movKitZMosa - 53.374));
		model = glm::rotate(model, glm::radians(rotKitMosa), glm::vec3(0.0f, 1.0f, 0.0));
		model = glm::rotate(model, glm::radians(-rotMosa), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		MosaCola.Draw(lightingShader);

		// CUELLOS LARGO
		// CUELLO LARGO 1
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-57.729, 0, 94.079));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LargoCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-56.991, 5.4, 101.396));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotLargoCola), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LargoCola.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-57.086, 10.585, 88.203));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotLargoCuello), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LargoCuello.Draw(lightingShader);

		// CUELLO LARGO 2
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-36.407, 0, 75.328));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LargoCuerpo2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-28.934, 5.370, 74.625));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotLargoCola2), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LargoCola2.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-42.396, 10.651, 74.675));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(-rotLargoCuello2), glm::vec3(0.0f, 0.0f, 1.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LargoCuello2.Draw(lightingShader);
		
		// Personas en GRADAS
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		GradasPies.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-33.919f, 1.387f, -119.230f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-11.836f, 1.387f, -119.230f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-20.508f, 3.866f, -123.732f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-34.127f, 6.153f, -127.451f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-5.158f, 6.153f, -127.451f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-33.908f, 1.382f, -119.236f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-11.818f, 1.277f, -119.236f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-20.462f, 3.786f, -123.739f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-34.045f, 6.165f, -127.467f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-5.179f, 6.051f, -127.711f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegoCabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-34.540, 5.075, -119.419));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegorHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-12.453, 4.985, -119.523));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegorHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-21.138, 7.491, -123.927));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegorHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-34.693, 9.866, -127.663));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegorHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-5.814, 9.727, -127.903));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegorHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-33.170, 5.066, -119.392));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegolHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-11.109, 4.986, -119.475));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegolHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-19.763, 7.498, -123.898));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegolHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-33.341, 9.878, -127.599));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegolHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(-4.482, 9.732, -127.882));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rotMano), glm::vec3(1.0f, 0.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		LegolHand.Draw(lightingShader);

		// PERSONAS CASAS
		// PERSONA CASA 1
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 59.376f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3Cuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 59.376f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3lHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 59.376f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3lPie.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 59.376f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3rPie.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.794f, 2.985f, 59.376f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rot3LegoC), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3Cabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.790f, 2.598f, 59.820f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rot3LegoM), glm::vec3(0.0f, 0.0f, 1.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3rHand.Draw(lightingShader);

		// PERSONA 2 CASA
		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 92.334f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3Cuerpo.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 92.334f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3lHand.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 92.334f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3lPie.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.791f, 0.147f, 92.334f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3rPie.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.794f, 2.985f, 92.341f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rot3LegoC), glm::vec3(0.0f, 1.0f, 0.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3Cabeza.Draw(lightingShader);

		view = camera.GetViewMatrix();
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(58.790f, 2.598f, 92.769f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		model = glm::rotate(model, glm::radians(rot3LegoM), glm::vec3(0.0f, 0.0f, 1.0));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		Lego3rHand.Draw(lightingShader);

		// ANIMACION AGUA
		Anim2.Use();
		tiempo = glfwGetTime();
		modelLoc = glGetUniformLocation(Anim2.Program, "model");
		viewLoc = glGetUniformLocation(Anim2.Program, "view");
		projLoc = glGetUniformLocation(Anim2.Program, "projection");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(Anim2.Program, "time"), tiempo);
		model = glm::mat4(1);
		model = glm::translate(tmp, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::translate(model, glm::vec3(posX, posY, posZ));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		Agua.Draw(Anim2);

	
		//Traslucidez

		/*glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::mat4(1);
		model = glm::scale(model, glm::vec3(1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform1f(glGetUniformLocation(lightingShader.Program, "transparencia"), 0.0);
		objTras.Draw(lightingShader);
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		*/
		glBindVertexArray(0);


		// Also draw the lamp object, again binding the appropriate shader
		lampShader.Use();
		// Get location objects for the matrices on the lamp shader (these could be different on a different shader)
		modelLoc = glGetUniformLocation(lampShader.Program, "model");
		viewLoc = glGetUniformLocation(lampShader.Program, "view");
		projLoc = glGetUniformLocation(lampShader.Program, "projection");

		// Set matrices
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		model = glm::mat4(1);
		model = glm::translate(model, lightPos);
		//model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		// Draw the light object (using light's vertex attributes)
		glBindVertexArray(lightVAO);
		for (GLuint i = 0; i < 4; i++)
		{
			model = glm::mat4(1);
			model = glm::translate(model, pointLightPositions[i]);
			model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		glBindVertexArray(0);


		// Draw skybox as last
		glDepthFunc(GL_LEQUAL);  // Change depth function so depth test passes when values are equal to depth buffer's content
		SkyBoxshader.Use();
		view = glm::mat4(glm::mat3(camera.GetViewMatrix()));	// Remove any translation component of the view matrix
		glUniformMatrix4fv(glGetUniformLocation(SkyBoxshader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(SkyBoxshader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		// skybox cube
		glBindVertexArray(skyboxVAO);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		glDepthFunc(GL_LESS); // Set depth function back to default

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &lightVAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &skyboxVAO);
	glDeleteBuffers(1, &skyboxVBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();

	return 0;
}


void animacion()
{
	//Movimiento del coche 1
	if (circuito)
	{
		if (recorrido1)
		{
			movKitX -= 0.3f;
			if (movKitX < -117)
			{
				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if (recorrido2)
		{
			rotKitCoche1 = 270;
			movKitZ -= 0.3f;
			if (movKitZ < -177)
			{
				recorrido2 = false;
				recorrido3 = true;

			}
		}

		if (recorrido3)
		{
			rotKitCoche1 = 0;
			movKitX -= 0.3f;
			if (movKitX < -129)
			{
				recorrido3 = false;
				recorrido4 = true;

			}
		}

		if (recorrido4)
		{
			rotKitCoche1 = 90;
			movKitZ += 0.3f;
			if (movKitZ > 13)
			{
				recorrido4 = false;
				recorrido5 = true;
			}
		}

		if (recorrido5)
		{
			rotKitCoche1 = 180;
			movKitX += 0.3f;
			if (movKitX > 0)
			{
				recorrido5 = false;
				recorrido6 = true;
			}
		}

		if (recorrido6)
		{
			rotKitCoche1 = 270;
			movKitZ -= 0.3f;
			if (movKitZ < 0)
			{
				recorrido6 = false;
				recorrido7 = true;
			}
		}

		if (recorrido7)
		{
			rotKitCoche1 = 0;
			movKitX -= 0.3f;
			if (movKitX < -117)
			{
				recorrido7 = false;
				recorrido1 = true;
			}
		}

	}

	// Movimiento de Coche 2
	if (circuitoCoche2)
	{
		if (recorrido1Coche2)
		{
			movKitZCoche2 -= 0.3f;
			if (movKitZCoche2 < -149)
			{
				recorrido1Coche2 = false;
				recorrido2Coche2 = true;
			}
		}
		if (recorrido2Coche2)
		{
			rotKitCoche2 = 90;
			movKitXCoche2 -= 0.3f;
			if (movKitXCoche2 < -53)
			{
				recorrido2Coche2 = false;
				recorrido3Coche2 = true;

			}
		}

		if (recorrido3Coche2)
		{
			rotKitCoche2 = 180;
			movKitZCoche2 += 0.3f;
			if (movKitZCoche2 > -136)
			{
				recorrido3Coche2 = false;
				recorrido4Coche2 = true;

			}
		}

		if (recorrido4Coche2)
		{
			rotKitCoche2 = 270;
			movKitXCoche2 += 0.3f;
			if (movKitXCoche2 > -13)
			{
				recorrido4Coche2 = false;
				recorrido5Coche2 = true;
			}
		}

		if (recorrido5Coche2)
		{
			rotKitCoche2 = 180;
			movKitZCoche2 += 0.3f;
			if (movKitZCoche2 > 0)
			{
				recorrido5Coche2 = false;
				recorrido6Coche2 = true;
			}
		}

		if (recorrido6Coche2)
		{
			rotKitCoche2 = 270;
			movKitXCoche2 += 0.3f;
			if (movKitXCoche2 > 0)
			{
				recorrido6Coche2 = false;
				recorrido7Coche2 = true;
			}
		}

		if (recorrido7Coche2)
		{
			rotKitCoche2 = 0;
			movKitZCoche2 -= 0.3f;
			if (movKitZCoche2 < -149)
			{
				recorrido7Coche2 = false;
				recorrido1Coche2 = true;
			}
		}

	}

	// Movimiento de Coche 3
	if (circuitoCoche3)
	{
		if (recorrido1Coche3)
		{
			movKitXCoche3 += 0.3f;
			if (movKitXCoche3 > 38)
			{
				recorrido1Coche3 = false;
				recorrido2Coche3 = true;
			}
		}
		if (recorrido2Coche3)
		{
			rotKitCoche3 = 270;
			movKitZCoche3 += 0.3f;
			if (movKitZCoche3 > 140)
			{
				recorrido2Coche3 = false;
				recorrido3Coche3 = true;

			}
		}

		if (recorrido3Coche3)
		{
			rotKitCoche3 = 0;
			movKitXCoche3 += 0.3f;
			if (movKitXCoche3 > 50)
			{
				recorrido3Coche3 = false;
				recorrido4Coche3 = true;

			}
		}

		if (recorrido4Coche3)
		{
			rotKitCoche3 = 90;
			movKitZCoche3 -= 0.3f;
			if (movKitZCoche3 < -12)
			{
				recorrido4Coche3 = false;
				recorrido5Coche3 = true;
			}
		}

		if (recorrido5Coche3)
		{
			rotKitCoche3 = 180;
			movKitXCoche3 -= 0.3f;
			if (movKitXCoche3 < 0)
			{
				recorrido5Coche3 = false;
				recorrido6Coche3 = true;
			}
		}

		if (recorrido6Coche3)
		{
			rotKitCoche3 = 270;
			movKitZCoche3 += 0.3f;
			if (movKitZCoche3 > 0)
			{
				recorrido6Coche3 = false;
				recorrido7Coche3 = true;
			}
		}

		if (recorrido7Coche3)
		{
			rotKitCoche3 = 0;
			movKitXCoche3 += 0.3f;
			if (movKitXCoche3 > 38)
			{
				recorrido7Coche3 = false;
				recorrido1Coche3 = true;
			}
		}

	}

	// Movimiento de Coche 4
	if (circuitoCoche4)
	{
		if (recorrido1Coche4)
		{
			movKitZCoche4 += 0.3f;
			if (movKitZCoche4 > 188)
			{
				recorrido1Coche4 = false;
				recorrido2Coche4 = true;
			}
		}
		if (recorrido2Coche4)
		{
			rotKitCoche4 = 90;
			movKitXCoche4 += 0.3f;
			if (movKitXCoche4 > 128)
			{
				recorrido2Coche4 = false;
				recorrido3Coche4 = true;

			}
		}

		if (recorrido3Coche4)
		{
			rotKitCoche4 = 180;
			movKitZCoche4 -= 0.3f;
			if (movKitZCoche4 < 176)
			{
				recorrido3Coche4 = false;
				recorrido4Coche4 = true;

			}
		}

		if (recorrido4Coche4)
		{
			rotKitCoche4 = 270;
			movKitXCoche4 -= 0.3f;
			if (movKitXCoche4 < 13)
			{
				recorrido4Coche4 = false;
				recorrido5Coche4 = true;
			}
		}

		if (recorrido5Coche4)
		{
			rotKitCoche4 = 180;
			movKitZCoche4 -= 0.3f;
			if (movKitZCoche4 < 0)
			{
				recorrido5Coche4 = false;
				recorrido6Coche4 = true;
			}
		}

		if (recorrido6Coche4)
		{
			rotKitCoche4 = 270;
			movKitXCoche4 -= 0.3f;
			if (movKitXCoche4 < 0)
			{
				recorrido6Coche4 = false;
				recorrido7Coche4 = true;
			}
		}

		if (recorrido7Coche4)
		{
			rotKitCoche4 = 0;
			movKitZCoche4 += 0.3f;
			if (movKitZCoche4 > 188)
			{
				recorrido7Coche4 = false;
				recorrido1Coche4 = true;
			}
		}

	}

	// Animacion Pterodactilo
	if (circuitoPtero)
	{
		animPtero1 = true;
		if (recorrePtero1)
		{
			movKitZPtero -= 0.1f;
			if (movKitZPtero < -50)
			{
				recorrePtero1 = false;
				recorrePtero2 = true;
			}
		}

		if (recorrePtero2)
		{
			rotKitPtero = 225;
			movKitXPtero += 0.1f;
			movKitZPtero += 0.1f;
			if (movKitZPtero > 0)
			{
				recorrePtero2 = false;
				recorrePtero3 = true;
			}
		}

		if (recorrePtero3)
		{
			rotKitPtero = 0;
			movKitZPtero -= 0.1f;
			if (movKitZPtero < -50)
			{
				recorrePtero3 = false;
				recorrePtero4 = true;
			}
		}

		if (recorrePtero4)
		{
			rotKitPtero = 135;
			movKitXPtero -= 0.1f;
			movKitZPtero += 0.1f;
			if (movKitZPtero > 0)
			{
				recorrePtero4 = false;
				recorrePtero5 = true;
			}
		}

		if (recorrePtero5)
		{
			rotKitPtero = 0;
			movKitZPtero -= 0.1f;
			if (movKitZPtero < -50)
			{
				recorrePtero5 = false;
				recorrePtero1 = true;
			}
		}
	}

	//Animacion T-Rex
	if (circuitoTRex) {
		animTRex1 = true;
		if (recorreTRex1) {
			movKitZT -= 0.1f;
			if (movKitZT < -40) {
				rotKitT = 90;
				movKitZT = -140;
				movKitXT = -80;
				recorreTRex1 = false;
				recorreTRex2 = true;
			}
		}

		if (recorreTRex2) {

			movKitXT -= 0.1f;
			if (movKitXT < -120) {
				rotKitT = -135;
				movKitZT = 0;
				movKitXT = -200;
				recorreTRex2 = false;
				recorreTRex3 = true;
			}
		}

		if (recorreTRex3) {

			movKitZT += 0.1f;
			movKitXT += 0.1f;
			if (movKitXT > -150) {
				rotKitT = 0;
				movKitZT = 0;
				movKitXT = 10;
				recorreTRex3 = false;
				recorreTRex1 = true;
			}
		}
	}

	//Animacion Velociraptor
	if (circuitoVel) {
		animTRex1 = true;
		if (recorreVel1) {
			movKitZV -= 0.1f;
			if (movKitZV < -40) {
				rotKitV = 90;
				movKitZV = -140;
				movKitXV = -80;
				recorreVel1 = false;
				recorreVel2 = true;
			}
		}

		if (recorreVel2) {
			movKitXV -= 0.1f;
			if (movKitXV < -120) {
				rotKitV = -135;
				movKitZV = 0;
				movKitXV = -200;
				recorreVel2 = false;
				recorreVel3 = true;
			}
		}

		if (recorreVel3) {

			movKitZV += 0.1f;
			movKitXV += 0.1f;
			if (movKitXV > -150) {
				rotKitV = 0;
				movKitZV = 0;
				movKitXV = 10;
				recorreVel3 = false;
				recorreVel1 = true;
			}
		}
	}

	// ANIMACION MOSA
	if (circuitoMosa)
	{
		animMosa1 = true;
		if (recorreMosa1)
		{
			movKitZMosa -= 0.1f;
			if (movKitZMosa < -40)
			{
				recorreMosa1 = false;
				recorreMosa2 = true;
			}
		}

		if (recorreMosa2)
		{
			rotKitMosa = 90;
			movKitXMosa -= 0.1f;
			if (movKitXMosa < -40)
			{
				recorreMosa2 = false;
				recorreMosa3 = true;
			}
		}

		if (recorreMosa3)
		{
			rotKitMosa = 225;
			movKitZMosa += 0.1f;
			movKitXMosa += 0.1f;
			if (movKitXMosa > -5)
			{
				recorreMosa3 = false;
				recorreMosa4 = true;
			}
		}

		if (recorreMosa4)
		{
			rotKitMosa = 90;
			movKitXMosa -= 0.1f;
			if (movKitXMosa < -40)
			{
				recorreMosa4 = false;
				recorreMosa5 = true;
			}
		}

		if (recorreMosa5)
		{
			rotKitMosa = 0;
			movKitZMosa -= 0.1f;
			if (movKitZMosa < -40)
			{
				recorreMosa5 = false;
				recorreMosa6 = true;
			}
		}

		if (recorreMosa6)
		{
			rotKitMosa = 225;
			movKitZMosa += 0.1f;
			movKitXMosa += 0.1f;
			if (movKitXMosa > -5)
			{
				recorreMosa6 = false;
				recorreMosa7 = true;
			}
		}

		if (recorreMosa7)
		{
			rotKitMosa = 0;
			movKitZMosa -= 0.1f;
			if (movKitZMosa < -40)
			{
				recorreMosa7 = false;
				recorreMosa1 = true;
			}
		}
	}
}


// Is called whenever a key is pressed/released via GLFW
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mode)
{

	if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			keys[key] = false;
		}
	}

	if (keys[GLFW_KEY_SPACE])
	{
		active = !active;
		if (active)
			LightP1 = glm::vec3(1.0f, 0.0f, 0.0f);
		else
			LightP1 = glm::vec3(0.0f, 0.0f, 0.0f);
	}

	// Teclas animacion COMPLEJA COCHE
	if (keys[GLFW_KEY_1])
	{
		circuito = true;
		circuitoCoche2 = true;
		circuitoCoche3 = true;
		circuitoCoche4 = true;
	}

	if (keys[GLFW_KEY_2])
	{
		circuito = false;
		circuitoCoche2 = false;
		circuitoCoche3 = false;
		circuitoCoche4 = false;
	}

	// Teclas animacion compleja PTERODACTILO
	if (keys[GLFW_KEY_3])
	{
		circuitoPtero = true;
		animPtero1 = true;
	}

	if (keys[GLFW_KEY_4])
	{
		circuitoPtero = false;
		animPtero1 = false;
	}

	// Teclas animación de PUERTAS
	if (keys[GLFW_KEY_5])
	{
		animaPuerta1 = true;
		animaPuerta2 = false;
	}

	if (keys[GLFW_KEY_6])
	{
		animaPuerta2 = true;
		animaPuerta1 = false;
	}

	// Teclas animacion compleja MOSA
	if (keys[GLFW_KEY_7])
	{
		circuitoMosa = true;
		animMosa1 = true;
	}

	if (keys[GLFW_KEY_8])
	{
		circuitoMosa = false;
		animMosa1 = false;
	}

	// Teclas animacion compleja Trex
	if (keys[GLFW_KEY_9])
	{
		circuitoTRex = true;
		animTRex1 = true;
		circuitoVel = true;
	}

	if (keys[GLFW_KEY_0])
	{
		circuitoTRex = false;
		animTRex1 = false;
		circuitoVel = false;
	}

}

void MouseCallback(GLFWwindow *window, double xPos, double yPos)
{

	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	GLfloat xOffset = xPos - lastX;
	GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset);
}

// Moves/alters the camera positions based on user input
void DoMovement()
{

	// Camera controls
	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
	{
		camera.ProcessKeyboard(FORWARD, deltaTime+0.05);

	}

	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
	{
		camera.ProcessKeyboard(BACKWARD, deltaTime+0.05);


	}

	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
	{
		camera.ProcessKeyboard(LEFT, deltaTime+0.05);


	}

	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
	{
		camera.ProcessKeyboard(RIGHT, deltaTime+0.05);
	}

	// ANIMACION PUERTA 
	if (animaPuerta1)
	{
		if (rotPuerta <= 90)
		{
			rotPuerta += 0.5;
		}
	}

	if (animaPuerta2)
	{
		if (rotPuerta >= 0)
		{
			rotPuerta -= 0.5;
		}
	}

	// ANIMACION ALAS PTERODACTILO
	if (animPtero1)
	{
		if (animPtero2)
		{
			rotPtero += 0.5;
			if (rotPtero > 25)
			{
				animPtero2 = false;
				animPtero3 = true;
			}
		}

		if (animPtero3)
		{
			rotPtero -= 0.5;
			if (rotPtero < -25)
			{
				animPtero3 = false;
				animPtero2 = true;
			}
		}
	}

	//ANIMACION PATAS, BRAZOS Y COLA DEL TREX Y VELOCIRAPTOR
	if (animTRex1) {
		if (animTRex2) {
			rotT += 0.5f;
			if (rotT > 35.0f) {
				animTRex2 = false;
				animTRex3 = true;
			}
		}

		if (animTRex3) {
			rotT -= 0.5f;
			if (rotT < -35.0f) {
				animTRex3 = false;
				animTRex2 = true;
			}
		}

		if (animTRex4) {
			rotTM += 0.2;
			if (rotTM > 10.0f) {
				animTRex4 = false;
				animTRex5 = true;
			}
		}

		if (animTRex5) {
			rotTM -= 0.2;
			if (rotTM < -10.0f) {
				animTRex5 = false;
				animTRex4 = true;
			}
		}
	}

	// ANIMACION COLA MOSA
	if (animMosa1)
	{
		if (animMosa2)
		{
			rotMosa += 0.5;
			if (rotMosa > 45)
			{
				animMosa2 = false;
				animMosa3 = true;
			}
		}

		if (animMosa3)
		{
			rotMosa -= 0.5;
			if (rotMosa < -45)
			{
				animMosa3 = false;
				animMosa2 = true;
			}
		}

		if (animMosa4)
		{
			traMosa -= 0.01;
			if (traMosa < -1.5)
			{
				animMosa4 = false;
				animMosa5 = true;
			}
		}

		if (animMosa5)
		{
			traMosa += 0.01;
			if (traMosa > 1.5)
			{
				animMosa5 = false;
				animMosa4 = true;
			}
		}
	}

	// ANIMACION CUELLO LARGO
	if (animaCuello1)
	{
		if (animaCuello2)
		{
			rotLargoCuello -= 0.2;
			if (rotLargoCuello < -35)
			{
				animaCuello2 = false;
				animaCuello3 = true;
			}
		}

		if (animaCuello3)
		{
			rotLargoCuello += 0.2;
			if (rotLargoCuello > 0)
			{
				animaCuello3 = false;
				animaCuello2 = true;
			}
		}

		if (animaCuello4)
		{
			rotLargoCola -= 0.4;
			if (rotLargoCola < -25)
			{
				animaCuello4 = false;
				animaCuello5 = true;
			}
		}

		if (animaCuello5)
		{
			rotLargoCola += 0.4;
			if (rotLargoCola > 25)
			{
				animaCuello5 = false;
				animaCuello4 = true;
			}
		}
	}

	if (anima2Cuello1)
	{
		if (anima2Cuello2)
		{
			rotLargoCuello2 -= 0.2;
			if (rotLargoCuello2 < -35)
			{
				anima2Cuello2 = false;
				anima2Cuello3 = true;
			}
		}

		if (anima2Cuello3)
		{
			rotLargoCuello2 += 0.2;
			if (rotLargoCuello2 > 0)
			{
				anima2Cuello3 = false;
				anima2Cuello2 = true;
			}
		}

		if (anima2Cuello4)
		{
			rotLargoCola2 -= 0.4;
			if (rotLargoCola2 < -25)
			{
				anima2Cuello4 = false;
				anima2Cuello5 = true;
			}
		}

		if (anima2Cuello5)
		{
			rotLargoCola2 += 0.4;
			if (rotLargoCola2 > 25)
			{
				anima2Cuello5 = false;
				anima2Cuello4 = true;
			}
		}
	}

	// ANIMACION MANOS GRADAS
	if (animaMano1)
	{
		if (animaMano2)
		{
			rotMano -= 1.0;
			if (rotMano < -90)
			{
				animaMano2 = false;
				animaMano3 = true;
			}
		}

		if (animaMano3)
		{
			rotMano += 1.0;
			if (rotMano > 0)
			{
				animaMano3 = false;
				animaMano2 = true;
			}
		}
	}

	// ANIMACION PERSONAS CASAS
	if (anima3Lego1)
	{
		if (anima3Lego2)
		{
			rot3LegoM += 1.0;
			if (rot3LegoM > 90)
			{
				anima3Lego2 = false;
				anima3Lego3 = true;
			}
		}

		if (anima3Lego3)
		{
			rot3LegoM -= 1.0;
			if (rot3LegoM < 0)
			{
				anima3Lego3 = false;
				anima3Lego2 = true;
			}
		}

		if (anima3Lego4)
		{
			rot3LegoC -= 0.5;
			if (rot3LegoC < -45)
			{
				anima3Lego4 = false;
				anima3Lego5 = true;
			}
		}

		if (anima3Lego5)
		{
			rot3LegoC += 0.5;
			if (rot3LegoC > 45)
			{
				anima3Lego5 = false;
				anima3Lego4 = true;
			}
		}
	}
}