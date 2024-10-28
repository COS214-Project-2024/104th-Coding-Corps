Government hierarchy ReadMe...

--------------------------------------------------------------
Government:

ATTRIBUTES:
- [citizenList : vector<AbstractCitizen*>] list of citizens
- [command : Command*] maintains reference to command
- [resourceManager : ResourceManager&] maintains reference to the singleton unique instance of resourceManager
- [uniqueInstance : Government*] maintains reference to the singleton unique instance for government
- [budget : Budget&] maintains reference to the singleton unique instance of budget
- [-Government()] constructs a default government and initialises other singleton attributes

METHODS:
- [+static Government* instance()] ensures Singleton pattern
- [void setCommand(Command* c)] sets the command attribute
- [void issueCommand()] tells command to execute
- [void increaseBudget(double amount)] calls addRevenue function from Budget
- [void decreaseBudget(double amount)] calls decreaseBudget function from Budget
- [void notifyResourceChange(std::string resourceType, int quantity)] notifies citizen observers so they can update appropriately
- [void addResourceToCity(std::string resourceType, int quantity, const ResourceFactory factory)] invokes resource manager add method
- [void displayCityResources()]invokes resource manager display method
- [bool useResource(const std::string& type, int quantity)] invokes resource manager consume method

--------------------------------------------------------------

--------------------------------------------------------------
Command:

METHODS:
- [virtual void execute = 0] defines a pure virtual function to execute commands
--------------------------------------------------------------

--------------------------------------------------------------
TaxationCommand:

ATTRIBUTES:
- [-citizenList : vector<AbstractCitizen*>] A list of citizens
- [-taxRate : double] the tax rate that is meant to be applied

METHODS:
- [+TaxationCommand(std::vector<AbstractCitizen*> c, double rate)] constructor for taxation command
- [+execute()] executes command by using visitor to visit each citizen in list and make them pay tax

--------------------------------------------------------------

--------------------------------------------------------------
PolicyCommand:

ATTRIBUTES:
- [-district : BuildingComposite*] maintains a reference to a buildingComposite which represents a district
- [-policy : string] the type of policy that is meant to be executed

METHODS:
- [+PolicyCommand(BuildingComposite* d, std::string policy)] constructor for policy command class
- [+execute()] executes command by calling district->enforcePolicy(policyType) from BuildingComposite class
--------------------------------------------------------------

--------------------------------------------------------------
Visitor:

METHODS:
- [virtual void visit(AbstractCitizen& citizen) = 0] defines a pure virtual function for Visitor
--------------------------------------------------------------

--------------------------------------------------------------
TaxCollector:

METHODS:
- [visit(AbstractCitizen& citizen)] implements the visit function by calling citizens calculate tax and pay tax methods
--------------------------------------------------------------



