using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.IO;

namespace ApiGateway.Controllers
{
    [ApiController]
    [Route("api/agent")]
    public class AgentController : ControllerBase
    {
        [HttpPost]
        public IActionResult Execute([FromBody] AgentRequest request)
        {
            if (string.IsNullOrWhiteSpace(request?.Task))
                return BadRequest("Task cannot be empty");

            var exePath = Path.GetFullPath(
                Path.Combine(
                    AppContext.BaseDirectory,
                    "..", "..", "..", "..", "..",
                    "build",
                    "windows_ai_runtime.exe"
                )
            );

            if (!System.IO.File.Exists(exePath))
                return StatusCode(500, $"Runtime executable not found at: {exePath}");

            var psi = new ProcessStartInfo
            {
                FileName = exePath,
                Arguments = $"--agent \"{request.Task}\"",
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = true
            };

            using var process = Process.Start(psi);
            if (process == null)
                return StatusCode(500, "Failed to start runtime process");

            string output = process.StandardOutput.ReadToEnd();
            string error = process.StandardError.ReadToEnd();
            process.WaitForExit();

            if (process.ExitCode != 0)
                return StatusCode(500, $"Runtime error: {error}");

            return Ok(new
            {
                task = request.Task,
                result = int.Parse(output.Trim())
            });
        }
    }

    public class AgentRequest
    {
        public string Task { get; set; }
    }
}
