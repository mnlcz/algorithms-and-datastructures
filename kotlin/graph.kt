import java.util.*

class Graph<T_NODE : Comparable<T_NODE>> constructor(private val content: Map<T_NODE, List<T_NODE>>)
{
    fun dfs(firstElement: T_NODE, operation: (T_NODE) -> Unit)
    {
        val stack: Stack<T_NODE> = Stack()
        stack.push(firstElement)
        while(stack.isNotEmpty())
        {
            val current = stack.pop()
            operation(current)
            content[current]?.forEach { stack.push(it) }
        }
    }

    fun bfs(firstElement: T_NODE, operation: (T_NODE) -> Unit)
    {
        val queue: Queue<T_NODE> = LinkedList()
        queue.add(firstElement)
        while(queue.isNotEmpty())
        {
            val current = queue.remove()
            operation(current)
            content[current]?.forEach { queue.add(it) }
        }
    }

    // Using DFS algo
    fun hasPath(origin: T_NODE, destination: T_NODE): Boolean
    {
        val stack = Stack<T_NODE>()
        stack.push(origin)
        while(stack.isNotEmpty())
        {
            val current = stack.pop()
            if(current == destination) return true

            content[current]?.forEach { stack.push(it) }
        }
        return false
    }

    override fun toString(): String
    {
        var str = ""
        content.forEach { (k, v) -> str += "$k --> ${v.joinToString(", ", "[", "]")}\n" }
        return str
    }
}